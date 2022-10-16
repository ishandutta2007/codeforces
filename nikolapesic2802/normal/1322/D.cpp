
// Problem : D. Reality Show
// Contest : Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL : https://codeforces.com/contest/1322/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

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
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

//dp[n][n+m][n] (i,k,cnt) = nacina da uzmem prvih i, tako da je k trenutna granica, i imam cnt na njoj.
// dp[i][k][cnt] -> dp[i][k+1][cnt/2] + cnt * c[cnt]
// dp[i][k][cnt] -> dp[i-1][k][cnt+1] (Ako je l[i]==k)
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int l[n+1],s[n+1],c[n+m+1],dp[2][n+m+2][n+1],mx[n+m+2]={},oo=INT_MIN/2;
	for(int i=1;i<=n;i++)
		scanf("%i",&l[i]),mx[l[i]]++;
	for(int i=0;i<=n+m;i++)
		mx[i+1]+=mx[i]/2;
	for(int i=1;i<=n;i++)
		scanf("%i",&s[i]);
	for(int i=1;i<=n+m;i++)
		scanf("%i",&c[i]);
	for(int i=0;i<=n;i++){
		for(int k=1;k<=n+m+1;k++)
			for(int cnt=0;cnt<=mx[k];cnt++)
				dp[i&1][k][cnt]=oo;
		for(int k=n+m+1;k>0;k--){
			for(int cnt=0;cnt<=mx[k];cnt++){
				if(k==n+m+1){
					assert(cnt==0);
					dp[i&1][k][cnt]=0;
					continue;
				}
				if(i&&l[i]==k&&cnt+1<=mx[k]){
					dp[i&1][k][cnt]=max(dp[i&1][k][cnt],dp[i&1^1][k][cnt+1]-s[i]);
				}
				if(i)
					dp[i&1][k][cnt]=max(dp[i&1][k][cnt],dp[i&1^1][k][cnt]);
				dp[i&1][k][cnt]=max(dp[i&1][k][cnt],dp[i&1][k+1][cnt/2]+cnt*c[k]);
			}
		}
	}
	printf("%i\n",dp[n&1][1][0]);
	return 0;
}