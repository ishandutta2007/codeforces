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

const int N=1e5+5,oo=INT_MAX/2;
vector<pair<int,int> > minn(4*N);
void sett(int pos,int val,int l=0,int r=N-1,int i=1)
{
    if(l>pos||r<pos)
        return;
    if(l==r)
    {
        minn[i]={val,l};
        return;
    }
    int m=(l+r)>>1;
    sett(pos,val,l,m,2*i);
    sett(pos,val,m+1,r,2*i+1);
    minn[i]=min(minn[2*i],minn[2*i+1]);
}
pair<int,int> getMin(int x,int l=0,int r=N-1,int i=1)
{
    if(x<l)
        return {oo,oo};
    if(x>=r)
        return minn[i];
    int m=(l+r)>>1;
    return min(getMin(x,l,m,2*i),getMin(x,m+1,r,2*i+1));
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<pair<pair<pair<int,int>,pair<int,int> >,int> > p(n);
    vector<int> x,visited(n,-1),parent(n,-1);
    for(int i=0;i<n;i++)
        scanf("%i %i %i %i",&p[i].f.f.f,&p[i].f.f.s,&p[i].f.s.f,&p[i].f.s.s),p[i].s=i;
    sort(all(p));
    for(int i=0;i<n;i++)
        sett(i,p[i].f.f.s),x.pb(p[i].f.f.f);
    x.pb(oo);
    pair<int,int> sol=getMin(upper_bound(x.begin(),x.end(),0)-x.begin()-1);
    queue<int> q;
    while(sol.f==0)
        q.push(sol.s),visited[sol.s]=1,sett(sol.s,oo),parent[sol.s]=-1,sol=getMin(upper_bound(x.begin(),x.end(),0)-x.begin()-1);
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        sol=getMin(upper_bound(x.begin(),x.end(),p[tr].f.s.f)-x.begin()-1);
        while(sol.f<=p[tr].f.s.s)
            q.push(sol.s),visited[sol.s]=visited[tr]+1,sett(sol.s,oo),parent[sol.s]=tr,sol=getMin(upper_bound(x.begin(),x.end(),p[tr].f.s.f)-x.begin()-1);
    }
    int start;
    for(int i=0;i<n;i++)
        if(p[i].s==n-1)
            start=i;
    printf("%i\n",visited[start]);
    if(visited[start]!=-1){
        vector<int> soll={p[start].s};
        while(parent[start]!=-1)
            soll.pb(p[parent[start]].s),start=parent[start];
        reverse(all(soll));
        for(auto p:soll)
            printf("%i ",p+1);
    }
    return 0;
}