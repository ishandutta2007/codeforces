#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int INF = 1e18;
 
struct ConvexHullDynamic
{

    struct Line
    {
        int a, b; //y = ax + b
        double xLeft; //Stores the intersection wiith previous line in the convex hull. First line has -INF
 
        enum Type {line, maxQuery, minQuery} type;
        int val;
 
        explicit Line(int aa=0, int bb=0): a(aa), b(bb), xLeft(-INF), type(Type::line), val(0) {}
 
        int valueAt(int x) const
        {
            return a*x + b;
        }
        friend bool isParallel(const Line &l1, const Line &l2)
        {
            return l1.a == l2.a;
        }
        friend double intersectX(const Line &l1, const Line &l2)
        {
            return isParallel(l1, l2)?INF:1.0*(l2.b-l1.b)/(l1.a-l2.a);
        }
        
        bool operator<(const Line& l2) const
        {
            if(l2.type == line)
                return this->a < l2.a;
            if(l2.type == maxQuery)
                return this->xLeft < l2.val;
            if(l2.type == minQuery)
                return this->xLeft > l2.val;
            return 0;
        }
    };
 
    bool isMax;
    set<Line> hull;
 
    bool hasPrev(set<Line>::iterator it)
    {
        return it!=hull.begin();
    }    
    bool hasNext(set<Line>::iterator it)
    {
        return it!=hull.end() && next(it)!=hull.end();
    }
    bool irrelevant(const Line &l1, const Line &l2, const Line &l3)
    {
        return intersectX(l1, l3) <= intersectX(l1, l2);
    }
    bool irrelevant(set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it) && ( 
            (isMax && irrelevant(*prev(it), *it, *next(it))) 
            || (!isMax && irrelevant(*next(it), *it, *prev(it))));
    }
    //Updates xValue of line pointed by it
    set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
    {
        if( (isMax && !hasPrev(it)) || (!isMax && !hasNext(it)))
            return it;
        double val=intersectX(*it, isMax?(*prev(it)):(*next(it)));
        Line temp(*it);
        it=hull.erase(it);
        temp.xLeft=val;
        it=hull.insert(it, temp);
        return it;
    }
 
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}
 
    void addLine(int a, int b) //Add ax + b in logN time
    {
        Line l3=Line(a, b);
        auto it=hull.lower_bound(l3);
 
        //If parallel liune is already in set, one of the lines becomes irrelevant
        if(it!=hull.end() && isParallel(*it, l3))
        {
            if( (isMax && it->b<b) || (!isMax && it->b>b))
                it=hull.erase(it);
            else
                return;
        }
 
        it=hull.insert(it, l3);
        if(irrelevant(it))
        {
            hull.erase(it);
            return;
        }
 
        //Remove lines which became irrelevant after inserting
        while(hasPrev(it) && irrelevant(prev(it)))
            hull.erase(prev(it));
        while(hasNext(it) && irrelevant(next(it)))
            hull.erase(next(it));
 
        //Update xLine
        it=updateLeftBorder(it);
        if(hasPrev(it))
            updateLeftBorder(prev(it));
        if(hasNext(it))
            updateLeftBorder(next(it));
    }
 
    int getBest(int x)
    {
        Line q;
        q.val=x;
        q.type = isMax?Line::Type::maxQuery : Line::Type::minQuery;
 
        auto bestLine=hull.lower_bound(q);
        if(isMax)
            --bestLine;
        return bestLine->valueAt(x);
    }
};

const int N = 1e5 + 10;

vector<ConvexHullDynamic> seg(4*N,ConvexHullDynamic(0));

int n;
vi g[N];
int a[N];
int b[N];
int timer = 0;
int tin[N];
int tout[N];
int res[N];

void update(int node,int ss,int se,int id,int a,int b)
{
    if(ss > id || se < id) return;
    
    seg[node].addLine(a,b);
    
    if(ss == se) return;
    
    int mid = (ss + se)/2;
    
    if(mid >= id) update(node*2+1,ss,mid,id,a,b);
    else update(node*2+2,mid+1,se,id,a,b);
}

int query(int node,int ss,int se,int l,int r,int x)
{
    if(ss > r || se < l) return INF;
    
    if(l <= ss && se <= r) return seg[node].getBest(x);
    
    int mid = (ss + se)/2;
    
    return min(query(node*2+1,ss,mid,l,r,x) , query(node*2+2,mid+1,se,l,r,x));
}

void dfs(int node,int par = -1)
{
    tin[node] = timer;
    tout[node] = timer;
    timer++;
    
    for(auto x : g[node])
        if(x != par) 
    {
        dfs(x,node);
        tout[node] = tout[x];     
    }
    
    if(tin[node] < tout[node])
        res[node] = query(0,0,n-1,tin[node]+1,tout[node],a[node]);
    
    update(0,0,n-1,tin[node],b[node],res[node]);
}

signed main()
{
    fast;
    
    cin >> n;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    
    for(int i=1;i<=n;i++) cin >> b[i];
    
    int u,v;
    
    f(i,n-1)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    dfs(1);
    
    for(int i=1;i<=n;i++) cout << res[i] << ' ';
}