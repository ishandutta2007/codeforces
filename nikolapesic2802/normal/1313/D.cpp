// Problem : D. Happy New Year
// Contest : Codeforces Round #622 (Div. 2)
// URL : https://codeforces.com/contest/1313/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

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

const int N=2e5+1,L=1<<8;
int dp[N][L],n;
vector<pair<int,int> > in;
vector<set<int> > open;
vector<map<int,int> > nxtInd;
int calc(int tr,int msk){
	if(dp[tr][msk]!=-1)
		return dp[tr][msk];
	//printf("%i %i!\n",tr,msk);
	int points=0;
	if(__builtin_popcount(msk)&1)
		points+=in[tr].s-in[tr].f+1;
	if(tr==n-1)
		return dp[tr][msk]=points;
	int nxtMsk=0,ostalo=0;
	int cnt=0;
	for(auto p:open[tr]){
		if(nxtInd[tr+1].find(p)!=nxtInd[tr+1].end()){
			if(msk&(1<<cnt))
				nxtMsk|=1<<nxtInd[tr+1][p];
		}
		cnt++;
	}
	for(auto p:nxtInd[tr+1])
		if(!open[tr].count(p.f))
			ostalo|=1<<p.s;
	//assert((ostalo&nxtMsk)==0);
	dp[tr][msk]=calc(tr+1,nxtMsk)+points;
	for(int mm=ostalo;mm;mm=(mm-1)&ostalo)
		dp[tr][msk]=max(dp[tr][msk],calc(tr+1,nxtMsk|mm)+points);
	return dp[tr][msk];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	int m,k;
	scanf("%i %i %i",&n,&m,&k);
	vector<pair<int,int> > e;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		l--;r--;
		e.pb({l,i+1});
		e.pb({r+1,-i-1});
	}
	sort(all(e));
	int lst=e[0].f;
	set<int> tr;
	for(auto p:e){
		if(lst!=p.f){
			in.pb({lst,p.f-1});
			open.pb(tr);
			lst=p.f;
			map<int,int> nxt;
			int cnt=0;
			for(auto p:tr)
				nxt[p]=cnt++;
			nxtInd.pb(nxt);
		}
		if(p.s<0)
			tr.erase(-p.s-1);
		else
			tr.insert(p.s-1);
	}
	n=in.size();
	int sol=0;
	for(int i=0;i<(1<<open[0].size());i++)
		sol=max(sol,calc(0,i));
	printf("%i\n",sol);
	return 0;
}