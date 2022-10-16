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

const int N=1e5+5,mod=1e9+7;
vector<ll> a(N);
ll gg(ll a,ll b)
{
    if(b==0)
        return a;
    return gg(b,a%b);
}
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(ll a,ll b)
{
    return a*b%mod;
}
int sol;
vector<vector<int> > graf(N);
void solve(int tr,int par,vector<pair<ll,int> > cnt)
{
    vector<pair<ll,int> > trr;
    for(auto p:cnt)
        trr.pb({gg(p.f,a[tr]),p.s});
    trr.pb({a[tr],1});
    sort(all(trr));
    int sum=0;
    vector<pair<ll,int> > sve;
    for(int i=0;i<trr.size();i++)
    {
        if(i<trr.size()-1&&trr[i+1].f==trr[i].f)
        {
            trr[i+1].s+=trr[i].s;
            continue;
        }
        sve.pb(trr[i]);
        sum=add(sum,mul(trr[i].f,trr[i].s));
    }
    sol=add(sol,sum);
    for(auto p:graf[tr])
        if(p!=par)
            solve(p,tr,sve);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,c,d;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%i %i",&c,&d),c--,d--,graf[c].pb(d),graf[d].pb(c);
    solve(0,0,{});
    printf("%i\n",sol);
    return 0;
}