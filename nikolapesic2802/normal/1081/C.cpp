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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int N=2e3+5;
const int mod=998244353;
int m;
int dp[N][N];
int calc(int n,int k)
{
    if(n==0)
    {
        if(k==0)
            return 1;
        return 0;
    }
    if(k<0)
        return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k]=((ll)calc(n-1,k)+(ll)calc(n-1,k-1)*(m-1))%mod;
    return dp[n][k];
}
int main()
{
    memset(dp,-1,sizeof(dp));
	int n,k;
	scanf("%i %i %i",&n,&m,&k);
	printf("%i\n",((ll)calc(n-1,k)*m)%mod);
    return 0;
}