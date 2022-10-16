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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=1e5+5;
vector<vector<pair<int,int> > > graf(N);
vector<int> xr(N,-1),gaus(31);
void add(int x)
{
    for(int i=30;i>=0;i--)
    {
        if(x&(1<<i))
        {
            if(!gaus[i])
            {
                gaus[i]=x;
                break;
            }
            x^=gaus[i];
        }
    }
}
void dfs(int tr,int par)
{
    for(auto p:graf[tr])
    {
        if(p.f==par)
            continue;
        if(xr[p.f]!=-1)
        {
            add(xr[p.f]^xr[tr]^p.s);
            continue;
        }
        xr[p.f]=xr[tr]^p.s;
        dfs(p.f,tr);
    }
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
    {
        int a,b,d;
        scanf("%i %i %i",&a,&b,&d);
        a--;
        b--;
        graf[a].pb({b,d});
        graf[b].pb({a,d});
    }
    xr[0]=0;
    dfs(0,-1);
    int x=xr[n-1];
    for(int i=29;i>=0;i--)
        x=min(x,x^gaus[i]);
    printf("%i\n",x);
    return 0;
}