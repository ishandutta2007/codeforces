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

const int mod=1e9+7;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
const int N=2e5+5;
vector<pair<int,int> > b;
int n;
vector<int> S(4*N),F(4*N);
void build(int l=0,int r=n-1,int i=1)
{
    if(l==r)
    {
        S[i]=b[l].s;
        F[i]=b[l].f;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    S[i]=max(S[2*i],S[2*i+1]);
    F[i]=min(F[2*i],F[2*i+1]);
}
int getMaxS(int qs,int qe,int l=0,int r=n-1,int i=1)
{
    if(qs>r||qe<l||qs>qe)
        return 0;
    if(qs<=l&&qe>=r)
        return S[i];
    int m=(l+r)>>1;
    return max(getMaxS(qs,qe,l,m,2*i),getMaxS(qs,qe,m+1,r,2*i+1));
}
int first_smaller(int val,int l=0,int r=n-1,int i=1)
{
    if(l==r)
    {
        return l;
    }
    int m=(l+r)>>1;
    if(F[2*i+1]<=val)
        return first_smaller(val,m+1,r,2*i+1);
    return first_smaller(val,l,m,2*i);
}
vector<pair<int,int> > minn(4*N);
pair<int,int> merge(pair<int,int> a,pair<int,int> b){
    pair<int,int> sol={min(a.f,b.f),0};
    if(sol.f==a.f)
        sol.s=a.s;
    if(sol.f==b.f)
        sol.s=add(sol.s,b.s);
    return sol;
}
void addPos(int pos,pair<int,int> sta,int l=0,int r=n-1,int i=1)
{
    if(l>pos||r<pos)
        return;
    if(l==r)
    {
        minn[i].f+=sta.f;
        minn[i].s=add(minn[i].s,sta.s);
        return;
    }
    int m=(l+r)>>1;
    addPos(pos,sta,l,m,2*i);
    addPos(pos,sta,m+1,r,2*i+1);
    minn[i]=merge(minn[2*i],minn[2*i+1]);
}
pair<int,int> get(int qs,int qe,int l=0,int r=n-1,int i=1)
{
    if(qs>r||qe<l)
        return {INT_MAX/2,0};
    if(qs<=l&&qe>=r)
        return minn[i];
    int m=(l+r)>>1;
    return merge(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
}
int main()
{
    scanf("%i",&n);
    b.resize(n);
    for(int i=0;i<n;i++)
        scanf("%i %i",&b[i].f,&b[i].s);
    sort(all(b));
    for(int i=0;i<n;i++)
        addPos(i,{-b[i].f,0});
    build();
    pair<int,int> lastSol;
    for(int i=0;i<n;i++)
    {
        int pos=first_smaller(b[i].s);
        if(b[pos].f>b[i].s)
        {
            lastSol={b[i].s,1};
            addPos(i,lastSol);
            continue;
        }
        int l=0,r=pos;
        while(l<r)
        {
            int m=(l+r)>>1;
            if(getMaxS(m+1,pos)>=b[m].f)
                l=m+1;
            else
                r=m;
        }
        lastSol=get(l,pos);
        lastSol.f+=b[i].s;
        addPos(i,lastSol);
    }
    pair<int,int> sol={INT_MAX,0};
    for(int i=0;i<n;i++)
    {
        if(getMaxS(i+1,n)<b[i].f)
        {
            pair<int,int> tr=get(i,i);
            tr.f+=b[i].f;
            sol=merge(sol,tr);
        }
    }
    printf("%i\n",sol.s);
}