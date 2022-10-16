#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

ll gb=0,gs=0,len;
struct Line{
    ll k,n;
    Line()
    {
        k=0;n=0;
    }
    Line(ll pos)
    {
        k=pos;n=-pos*gs-gb;
    }
    ll val(ll pos)
    {
        return pos*k+n+gb;
    }
    ll val()
    {
        return gs*k+n+gb;
    }
};
long double to2(Line a,Line b)
{
    return (long double)(b.n-a.n)/(long double)(a.k-b.k);
}
ll to(Line a,Line b)
{
    ll lo=gs,hi=gs;
    while(a.val(hi)<b.val(hi))
    {
        lo=hi+1;
        hi*=2;
    }
    while(lo<hi)
    {
        ll m=(lo+hi)/2;
        if(a.val(m)<b.val(m))
            lo=m+1;
        else
            hi=m;
    }
    return lo;
}
struct ConvexHull{
    deque<Line> q;
    pair<ll,ll> get()
    {
        while(q.size()>1&&q[1].val()<=q[0].val())
            q.pop_front();
        return {q.front().val(),q.front().k};
    }
    void add(Line a)
    {
        if(q.size()&&a.val()>=q.front().val())
            return;
        while(q.size()>1&&to(a,q[0])>=to(q[0],q[1]))
            q.pop_front();
        q.push_front(a);
    }
    void clear()
    {
        q.clear();
    }
}ch;
struct LiChaoNode{
    Line tr;
    int le,ri;
    LiChaoNode()
    {
        le=-1;
    }
};
vector<LiChaoNode> nodes;
int newNode()
{
    LiChaoNode no;
    nodes.pb(no);
    int ret=nodes.size()-1;
    return ret;
}
int root;
ll limit=1;
void add(Line li,int tr=root,ll l=0,ll r=LLONG_MAX/limit)
{
    if(nodes[tr].le==-1)
    {
        nodes[tr].tr=li;
        int a=newNode();
        nodes[tr].le=a;
        a=newNode();
        nodes[tr].ri=a;
        return;
    }
    ll m=(l+r)>>1;
    bool lef=nodes[tr].tr.val(l)>li.val(l);
    bool mid=nodes[tr].tr.val(m)>li.val(m);
    if(mid)
        swap(nodes[tr].tr,li);
    if(r-l==1)
        return;
    if(mid!=lef)
        add(li,nodes[tr].le,l,m);
    else
        add(li,nodes[tr].ri,m,r);
}
pair<ll,ll> get(int tr=root,ll l=0,ll r=LLONG_MAX/limit)
{
    if(nodes[tr].le==-1)
        return {LLONG_MAX,LLONG_MAX};
    ll m=(l+r)>>1;
    if(r-l==1)
        return make_pair(nodes[tr].tr.val(),nodes[tr].tr.k);
    pair<ll,ll> trsol=make_pair(nodes[tr].tr.val(),nodes[tr].tr.k);
    if(gs<m)
        return min(trsol,get(nodes[tr].le,l,m));
    return min(trsol,get(nodes[tr].ri,m,r));
}
void reset()
{
    nodes.clear();
    int a=newNode();
    root=a;
}
int main()
{
    reset();
	int n,m;
	scanf("%i %i",&n,&m);
	len=n;
	int lol=m;
	Line a(0);
	add(a);
	queue<ll> input;
	int x=m;
	ll mylen=n;
	while(m--)
    {
        int t;
        scanf("%i",&t);
        input.push(t);
        if(t==1)
        {
            int k;
            scanf("%i",&k);
            mylen+=k;
            input.push(k);
        }
        if(t==2)
        {
            int k;
            scanf("%i",&k);
            limit=max(limit,mylen);
            mylen+=k;
            input.push(k);
        }
        if(t==3)
        {
            int b,s;
            scanf("%i %i",&b,&s);
            input.push(b);
            input.push(s);
        }
    }
    m=x;
	while(m--)
    {
        int t=input.front();
        input.pop();
        //scanf("%i",&t);
        if(t==1)
        {
            int k=input.front();
            input.pop();
            //scanf("%i",&k);
            len+=k;
            Line b(0);

            reset();
            add(b);

            /*ch.clear();
            ch.add(b);*/
        }
        if(t==2)
        {
            int k=input.front();
            input.pop();
            //scanf("%i",&k);
            Line b(len);
            len+=k;

            add(b);

            //ch.add(b);
        }
        if(t==3)
        {
            int b=input.front();
            input.pop();
            int s=input.front();
            input.pop();
            //scanf("%i %i",&b,&s);
            gb+=b;
            gs+=s;
        }
        printf("%lld %lld\n",get().s+1,get().f);
    }
    return 0;
}