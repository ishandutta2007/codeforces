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
set<vector<int> > s;
void gen(int num,int ostalo,vector<int> dosada)
{
    if(ostalo==0)
        return;
    if(num==1)
    {
        dosada.pb(ostalo);
        s.insert(dosada);
        return;
    }
    for(int i=1;i<ostalo;i++){
        dosada.pb(i);
        gen(num-1,ostalo-i,dosada);
        dosada.pop_back();
    }
}
const int mod=1e9+7;
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=(ll)x*x%mod)
        if(k&1)
            ans=(ll)ans*x%mod;
    return ans;
}
int inv(int x)
{
    return powmod(x,mod-2);
}
const int N=1e6+5;
vector<int> fact;
int nCk(int n,int k)
{
    return (ll)((ll)fact[n]*inv(fact[k])%mod)*inv(fact[n-k])%mod;
}
int main()
{
    fact.pb(1);
    for(int i=1;i<N;i++)
        fact.pb((ll)fact.back()*i%mod);
	int n,m;
	scanf("%i %i",&n,&m);
	int fin=0;
	for(int i=1;i<n;i++)
    {
        if(i>m)
            continue;
        int tr=nCk(m-1,i-1);
        tr=(ll)tr*powmod(m,n-1-i)%mod;
        tr=(ll)tr*fact[n-2]%mod;
        tr=(ll)tr*inv(fact[n-i-1])%mod;
        if(i<n-1)
            tr=(ll)tr*(i+1)%mod,tr=(ll)tr*powmod(n,n-i-2)%mod;
        fin=(fin+tr)%mod;
    }
    printf("%i\n",fin);
    return 0;
}