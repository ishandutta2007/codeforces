
// Problem : E. Sleeping Schedule
// Contest : Codeforces Round #627 (Div. 3)
// URL : https://codeforces.com/contest/1324/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

const int N=2001;
int dp[N][N];
int n,h,l,r;
vector<int> a(N);
int calc(int tr,int vr){
	if(tr==n)
		return 0;
	if(dp[tr][vr]!=-1)
		return dp[tr][vr];
	int op1=(vr+a[tr])%h,op2=(vr+a[tr]-1)%h;
	dp[tr][vr]=0;
	if(op1>=l&&op1<=r)
		dp[tr][vr]=max(dp[tr][vr],calc(tr+1,op1)+1);
	else
		dp[tr][vr]=max(dp[tr][vr],calc(tr+1,op1));
	if(op2>=l&&op2<=r)
		dp[tr][vr]=max(dp[tr][vr],calc(tr+1,op2)+1);
	else
		dp[tr][vr]=max(dp[tr][vr],calc(tr+1,op2));
	return dp[tr][vr];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i %i %i %i",&n,&h,&l,&r);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	printf("%i\n",calc(0,0));
	return 0;
}