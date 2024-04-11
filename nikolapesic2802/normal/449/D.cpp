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

const int mod=1e9+7,N=1<<20;
int mul(int a,int b)
{
    return (ll)a*b%mod;
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
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> cnt(N),nxt(N);
	vector<int> pwr;
	pwr.pb(1);
	for(int i=1;i<N;i++)
        pwr.pb(add(pwr.back(),pwr.back()));
	for(int i=0;i<n;i++){
        int a;
        scanf("%i",&a);
        cnt[a]++;
	}
	for(int i=0;i<20;i++)
    {
        for(int x=0;x<N;x++)
            if(x&(1<<i))
                nxt[x]=cnt[x];
            else
                nxt[x]=cnt[x]+cnt[x+(1<<i)];
        cnt=nxt;
    }
    //cout << cnt << endl;
    int ans=pwr[n];
    for(int mask=1;mask<N;mask++)
    {
        if(__builtin_popcount(mask)&1)
            ans=sub(ans,pwr[cnt[mask]]);
        else
            ans=add(ans,pwr[cnt[mask]]);
    }
    printf("%i\n",ans);
    return 0;
}