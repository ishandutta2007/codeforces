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
const int mod=1e9+7;
int main()
{
	int n,l,r;
	scanf("%i %i %i",&n,&l,&r);
	int number=r-l+1;
	int start=l%3;
	int ostatak=number%3;
	int doo=number/3;
	vector<int> cnt(3);
	cnt[0]=cnt[1]=cnt[2]=doo;
	for(int i=0;i<ostatak;i++)
    {
        cnt[start]++;
        start=(start+1)%3;
    }
    int dp[n+1][3];
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=((ll)cnt[0]*dp[i-1][0]+(ll)cnt[1]*dp[i-1][2]+(ll)cnt[2]*dp[i-1][1])%mod;
        dp[i][1]=((ll)cnt[1]*dp[i-1][0]+(ll)cnt[2]*dp[i-1][2]+(ll)cnt[0]*dp[i-1][1])%mod;
        dp[i][2]=((ll)cnt[2]*dp[i-1][0]+(ll)cnt[0]*dp[i-1][2]+(ll)cnt[1]*dp[i-1][1])%mod;
    }
    printf("%i\n",dp[n][0]);
    return 0;
}