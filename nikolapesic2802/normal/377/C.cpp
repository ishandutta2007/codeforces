
// Problem : C. Captains Mode
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/C
// Memory Limit : 256 MB
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

const int N=20;
vector<int> s(101);
vector<pair<int,int> > moves;
int n;
int dp[1<<N];
int calc(int msk){
	int tr=__builtin_popcount(msk);
	if(tr==n)
		return 0;
	if(dp[msk]!=-1)
		return dp[msk];
	if(moves[tr].s==1){
		dp[msk]=INT_MIN;
		for(int i=0;i<n;i++){
			if(msk&(1<<i))
				continue;
			if(moves[tr].f==0)
				dp[msk]=max(dp[msk],calc(msk|(1<<i))+s[i]);
			else
				dp[msk]=max(dp[msk],calc(msk|(1<<i)));
		}
	}
	else{
		dp[msk]=INT_MAX;
		for(int i=0;i<n;i++){
			if(msk&(1<<i))
				continue;
			if(moves[tr].f==0)
				dp[msk]=min(dp[msk],calc(msk|(1<<i))-s[i]);
			else
				dp[msk]=min(dp[msk],calc(msk|(1<<i)));
		}
	}
	return dp[msk];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%i",&s[i]);
	sort(s.rbegin(),s.rend());
	scanf("%i",&n);
	for(int i=0;i<n;i++){
		char c;
		int t;
		scanf(" %c %i",&c,&t);
		if(c=='p')
			moves.pb({0,t});
		else
			moves.pb({1,t});
	}
	printf("%i\n",calc(0));
	return 0;
}