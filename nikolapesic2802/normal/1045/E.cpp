#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

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
struct pt{
    int x,y,c,i;
    pt operator-(pt a){return {x-a.x,y-a.y,c,i};}
    pt operator+(pt a){return {x+a.x,y+a.y,c,i};}
};
bool operator==(pt a,pt b){return a.x==b.x&&a.y==b.y;}
ostream& operator<<(ostream& out,pt a){out << "[" << a.x << "," << a.y << "," << a.c << "," << a.i << "]"; return out;}
int cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
int sq(pt a){return a.x*a.x+a.y*a.y;}
ld abs(pt a){return sqrtl(sq(a));}
bool operator<(pt a,pt b){
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}
bool cmp(pt a,pt b){
    int x=cross(a,b);
    if(x==0)
    {
        return abs(a)<abs(b);
    }
    return x>0;
}
bool inside(pt c,vector<pt> poly)
{
    int cnt=0;
    for(int i=0,n=poly.size();i<n;i++)
    {
        if(poly[i]==c)
            return false;
        pt a=poly[i],b=poly[(i+1)%n];
        if(a.y==b.y)
            continue;
        if(a.y>b.y)
            swap(a,b);
        if(a.y>c.y||b.y<c.y)
            continue;
        int d1=c.y-a.y,d2=b.y-a.y;
        ld x=(ld)a.x+(ld)(b.x-a.x)*(ld)d1/(ld)d2;
        if(x==c.x)
            return false;
        if(x<=c.x)
            continue;
        if(a.y==c.y)
            continue;
        cnt++;
    }
    return cnt%2;
}
vector<pair<int,int> > roads;
void connect(pt start,vector<pt> po)
{
    for(auto d:po)
        roads.pb({start.i,d.i});
}
void print()
{
    printf("%i\n",roads.size());
    for(auto d:roads)
        printf("%i %i\n",d.f,d.s);
    exit(0);
}
int n,m;
void solve(pt a,pt b,pt c,vector<pt> in)
{
    vector<pt> mypoly={a,b,c};
    vector<pt> ii;
    for(auto p:in)
        if(inside(p,mypoly))
            ii.pb(p);
    in=ii;
    assert(a.c==b.c&&a.c!=c.c);
    pt notSame={0,0,-1,0};
    for(auto p:in)
        if(p.c!=a.c)
            notSame=p;
    if(notSame.c==-1)
    {
        connect(a,in);
        return;
    }
    roads.pb({notSame.i,c.i});
    solve(a,b,notSame,in);
    solve(c,notSame,b,in);
    solve(notSame,c,a,in);
}
int main()
{
	scanf("%i",&n);
	vector<pt> p(n);
	for(int i=0;i<n;i++)
        cin >> p[i].x >> p[i].y >> p[i].c,p[i].i=i;
    sort(all(p));
    for(int i=n-1;i>=0;i--)
        p[i]=p[i]-p[0];
    sort(all(p),cmp);
    vector<pt> hull(n);
    for(auto d:p)
    {
        while(m>1&&cross(d-hull[m-1],d-hull[m-2])>=0)
            m--;
        hull[m++]=d;
    }
    hull.resize(m);
    int prelazi=0;
    for(int i=0;i<m;i++)
        if(hull[i].c!=hull[(i+1)%m].c)
            prelazi++;
    if(prelazi!=0&&prelazi!=2)
    {
        printf("Impossible\n");
        return 0;
    }
    if(hull[0].c==1){
        for(auto &d:hull)
            d.c^=1;
        for(auto &d:p)
            d.c^=1;
    }
    if(prelazi==0)
    {
        for(int i=0;i<m-1;i++)
            roads.pb({hull[i].i,hull[i+1].i});
        pt start={-1,-1,-1,-1};
        vector<pt> inPoly;
        for(int i=0;i<n;i++)
            if(inside(p[i],hull)){
                if(p[i].c==1)
                    start=p[i];
                inPoly.pb(p[i]);
            }
        if(start.c==-1)
            connect(hull[0],inPoly),print();
        for(int i=0;i<m;i++)
            solve(hull[i],hull[(i+1)%m],start,inPoly);
        print();
    }
    else
    {
        int prvi=-1;
        for(int i=0;i<m;i++)
            if(hull[i].c==1)
            {
                prvi=i;
                break;
            }
        assert(prvi!=-1);
        vector<pt> nula,jedan;
        for(int i=0;i<m;i++)
        {
            if(hull[(prvi+i)%m].c==1)
                jedan.pb(hull[(prvi+i)%m]);
            else
                nula.pb(hull[(prvi+i)%m]);
        }
        assert(nula.size()&&jedan.size());
        for(int i=1;i<(int)jedan.size();i++)
            solve(jedan[i-1],jedan[i],nula[0],p),roads.pb({jedan[i-1].i,jedan[i].i});
        for(int i=1;i<(int)nula.size();i++)
            solve(nula[i-1],nula[i],jedan[0],p),roads.pb({nula[i-1].i,nula[i].i});
        print();
    }
    return 0;
}