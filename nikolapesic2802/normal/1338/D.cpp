
// Problem : D. Nested Rubber Bands
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/contest/1338/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

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
template<class T1, class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int N=1e5+5;
int dp[N][2];
int sol;
vector<vector<int> > graf(N);
void init(int tr,int par){
	int bst0=-N,bst1=-N,cnt=0;
	for(auto p:graf[tr]){
		if(p==par)
			continue;
		init(p,tr);
		cnt++;
		bst0=max(bst0,dp[p][0]);
		bst1=max(bst1,dp[p][1]);
	}
	if(cnt==0){
		dp[tr][0]=0;
		dp[tr][1]=1;
		return;
	}
	dp[tr][0]=max(bst0,bst1)+cnt-1;
	dp[tr][1]=bst0+1;
}
void dfs(int tr,int par,pair<int,int> up){
	int c=graf[tr].size();
	vector<pair<int,int> > vals;
	for(auto p:graf[tr]){
		if(p==par)
			vals.pb({up.f,up.s});
		else
			vals.pb({dp[p][0],dp[p][1]});
	}
	auto old=vals;
	vals.pb({-N,-N});
	for(int i=c-1;i>=0;i--)
		vals[i].f=max(vals[i].f,vals[i+1].f),vals[i].s=max(vals[i].s,vals[i+1].s);
	sol=max(sol,vals[0].f+1);
	pair<int,int> pre={-N,-N};
	for(int i=0;i<c;i++){
		pair<int,int> vl={max(pre.f,vals[i+1].f),max(pre.s,vals[i+1].s)};
		pre.f=max(pre.f,old[i].f);
		pre.s=max(pre.s,old[i].s);
		if(graf[tr][i]==par)
			continue;
		pair<int,int> sl={max(vl.f,vl.s)+c-2,vl.f+1};
		dfs(graf[tr][i],tr,sl);
	}
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%i %i",&a,&b);
		a--;b--;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	init(0,0);
	dfs(0,0,{0,0});
	printf("%i\n",sol);
	return 0;
}