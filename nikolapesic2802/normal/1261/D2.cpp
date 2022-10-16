#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=2e5+5,mod=998244353;
int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
int mul(int a,int b){return (ll)a*b%mod;}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
vector<int> fact(1,1),ifact(N);
vector<int> a(N);
int n,k;
int nCk(int n,int k)
{
    return mul(fact[n],mul(ifact[k],ifact[n-k]));
}
int main()
{
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
    ifact[N-1]=pwrmod(fact[N-1],mod-2);
    for(int i=N-2;i>=0;i--)
        ifact[i]=mul(ifact[i+1],i+1);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    scanf("%i %i",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    a[n]=a[0];
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]!=a[i+1])
            cnt++;
    int ans=0,inv=pwrmod(2,mod-2);
    for(int i=1;i<=cnt;i++)
    {
        int ways=nCk(cnt,i);
        int svi=pwrmod(2,i);
        if(i&1^1)
            svi=sub(svi,nCk(i,i/2));
        svi=mul(svi,inv);
        ways=mul(ways,svi);
        ways=mul(ways,pwrmod((k-2)%mod,cnt-i));
        ans=add(ans,ways);
    }
    ans=mul(ans,pwrmod(k,n-cnt));
    printf("%i\n",ans);
    return 0;
}