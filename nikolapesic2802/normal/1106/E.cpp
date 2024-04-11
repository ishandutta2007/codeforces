
// Problem : E. Lunar New Year and Red Envelopes
// Contest : Codeforces - Codeforces Round #536 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1106/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double
#define li __int128

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
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
ll dp[N][2];
int nxt[N],coins[N];
int main()
{
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	multiset<pair<int,int> > tr;
	vector<pair<int,int> > events[n+1];
	for(int i=0;i<k;i++){
		int l,r,d,w;
		scanf("%i %i %i %i",&l,&r,&d,&w);
		l--;r--;d--;
		events[l].pb({d,w});
		events[r+1].pb({d,-w});
	}
	for(int i=0;i<n;i++){
		for(auto p:events[i]){
			if(p.s>0){
				tr.insert({p.s,p.f});
			}
			else{
				tr.erase(tr.find({-p.s,p.f}));
			}
		}
		if(tr.empty()){
			nxt[i]=coins[i]=-1;
		}
		else{
			pair<int,int> ok=*tr.rbegin();
			nxt[i]=ok.s+1;
			coins[i]=ok.f;
		}
	}
	for(int j=0;j<=m;j++){
		for(int i=0;i<n;i++)
			dp[i][j&1]=0;
		for(int i=n-1;i>=0;i--){
			if(nxt[i]==-1)
				dp[i][j&1]=dp[i+1][j&1];
			else
				dp[i][j&1]=dp[nxt[i]][j&1]+coins[i];
			if(j)
				dp[i][j&1]=min(dp[i][j&1],dp[i+1][j&1^1]);
		}
	}
	printf("%lld\n",dp[0][m&1]);
	return 0;
}