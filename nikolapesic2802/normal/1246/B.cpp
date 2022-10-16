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
int n,k;

int mod=1e9+7;
int add(int a,int b)
{
	return (a+b)%mod;
}
int mul(int a,int b)
{
	return (ll)a*b%mod;
}
ll pwr(int st)
{
	ll kk=k,ans=1;
	for(;st;st>>=1,kk=mul(kk,kk))
		if(st&1)
			ans=mul(ans,kk);
	return ans;
}
pair<int,int> getHsh(int a)
{
	int hsh=0,inv=0;
        for(int j=2;j*j<=a;j++)
        {
            if(a%j==0)
            {
                int cnt=0;
                while(a%j==0)
                    cnt++,a/=j;
                cnt%=k;
                hsh=add(hsh,mul(pwr(j),cnt));
                inv=add(inv,mul(pwr(j),((k-cnt)%k)));
            }
            
        }
        if(a!=1)
            hsh=add(hsh,pwr(a)),inv=add(inv,mul(pwr(a),(k-1)));
   return {hsh,inv};
}
vector<int> ha;
int main()
{
	ha.pb(1e9+7);
	ha.pb(1e9+9);
	ha.pb(1e9+21);
	//ha.pb(1e9+33);
	scanf("%i %i",&n,&k);
	map<vector<int>,int> cnt;
	ll sol=0;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        vector<int> in,hs;
        for(int i=0;i<ha.size();i++)
        {
        	mod=ha[i];
        	pair<int,int> tr=getHsh(a);
        	in.pb(tr.f);
        	hs.pb(tr.s);
        }
        sol+=cnt[in];
        cnt[hs]++;
    }
    printf("%lld\n",sol);
    return 0;
}