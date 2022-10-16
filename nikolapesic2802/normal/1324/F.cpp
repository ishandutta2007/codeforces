
// Problem : F. Maximum White Subtree
// Contest : Codeforces Round #627 (Div. 3)
// URL : https://codeforces.com/contest/1324/problem/F
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

const int N=2e5+5;
vector<int> c(N);
int n;
vector<vector<int> > graf(N);
vector<vector<int> > dp(N);
int init(int tr,int par){
	dp[tr].resize(graf[tr].size());
	int sum=0;
	if(c[tr]==0)
		sum--;
	else
		sum++;
	for(int i=0;i<graf[tr].size();i++){
		int p=graf[tr][i];
		if(p==par){
			dp[tr][i]=-1;
			continue;
		}
		dp[tr][i]=init(p,tr);
		sum+=dp[tr][i];
	}
	return max(0,sum);
}
vector<int> ans(N);
int calc(int tr,int par,int up){
	for(int i=0;i<graf[tr].size();i++)
		if(dp[tr][i]==-1)
			dp[tr][i]=up;
	int s=0;
	if(c[tr]==0)
		s--;
	else
		s++;
	for(auto p:dp[tr])
		s+=p;
	ans[tr]=s;
	for(int i=1;i<graf[tr].size();i++)
		dp[tr][i]+=dp[tr][i-1];
	for(int i=0;i<graf[tr].size();i++){
		int p=graf[tr][i];
		if(p==par)
			continue;
		int sum=0;
		if(c[tr]==0)
			sum--;
		else
			sum++;
		if(i)
			sum+=dp[tr][i-1];
		sum+=dp[tr][dp[tr].size()-1]-dp[tr][i];
		calc(p,tr,max(0,sum));
	}
}
int main()
{
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%i",&c[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	init(0,0);
	calc(0,0,0);
	for(int i=0;i<n;i++)
		printf("%i ",ans[i]);
	return 0;
}