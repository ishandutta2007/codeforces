
// Problem : C. Nastya and Unexpected Guest
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : http://codeforces.com/contest/1340/problem/C
// Memory Limit : 0 MB
// Time Limit : 0 ms
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

const int M=1e4+5,N=1e3+5;
int dp[M][N],n,m,g,r;
vector<int> p;
queue<pair<int,int> > q[M+5];
void update(int tr,int t){
	if(tr!=0){
		int d=p[tr]-p[tr-1];
		if(d+t==g){
			if(dp[tr-1][0]==-1){
				dp[tr-1][0]=dp[tr][t]+1;
				q[dp[tr-1][0]].push({tr-1,0});
			}
		}
		if(d+t<g){
			if(dp[tr-1][d+t]==-1||dp[tr-1][d+t]>dp[tr][t]){
				dp[tr-1][d+t]=dp[tr][t];
				q[dp[tr-1][d+t]].push({tr-1,d+t});
			}
		}
	}
	if(tr!=m-1){
		int d=p[tr+1]-p[tr];
		if(d+t==g){
			if(dp[tr+1][0]==-1){
				dp[tr+1][0]=dp[tr][t]+1;
				q[dp[tr+1][0]].push({tr+1,0});
			}
		}
		if(d+t<g){
			if(dp[tr+1][d+t]==-1||dp[tr+1][d+t]>dp[tr][t]){
				dp[tr+1][d+t]=dp[tr][t];
				q[dp[tr+1][d+t]].push({tr+1,d+t});
			}
		}
	}
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i %i",&n,&m);
	p.resize(m);
	for(int i=0;i<m;i++){
		scanf("%i",&p[i]);
	}
	sort(all(p));
	scanf("%i %i",&g,&r);
	dp[0][0]=0;
	q[0].push({0,0});
	for(int i=0;i<M-1;i++){
		while(q[i].size()){
			pair<int,int> tr=q[i].front();
			q[i].pop();
			update(tr.f,tr.s);
		}
	}
	int sol=INT_MAX;
	for(int i=0;i<g;i++){
		if(dp[m-1][i]!=-1){
			if(i==0){
				sol=min(sol,dp[m-1][i]*(r+g)-r);
			}
			else
				sol=min(sol,dp[m-1][i]*(r+g)+i);
		}
	}
	if(sol==INT_MAX)
		sol=-1;
	printf("%i\n",sol);
	return 0;
}