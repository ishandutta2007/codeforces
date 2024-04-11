// Problem : F. Summoning Minions
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
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

const int N=76;
int n,k,dp[N][N];
vector<pair<pair<int,int>,int> > a;
int calc(int tr,int br){
	if(tr==n){
		if(br==k)
			return 0;
		return INT_MIN/2;
	}
	if(dp[tr][br]!=-1)
		return dp[tr][br];
	dp[tr][br]=INT_MIN/2;
	if(br<k)
		dp[tr][br]=max(dp[tr][br],calc(tr+1,br+1)+a[tr].f.s+br*a[tr].f.f);
	dp[tr][br]=max(dp[tr][br],calc(tr+1,br)+(k-1)*a[tr].f.f);
	//printf("%i %i: %i\n",tr,br,dp[tr][br]);
	return dp[tr][br];
}
vector<int> pick, ostali;
void gen(int tr,int br){
	if(tr==n)
		return;
	if(br<k&&dp[tr][br]==calc(tr+1,br+1)+a[tr].f.s+br*a[tr].f.f){
		pick.pb(a[tr].s);
		gen(tr+1,br+1);
	}
	else{
		ostali.pb(a[tr].s);
		gen(tr+1,br);
	}
}
void test(){
	memset(dp,-1,sizeof(dp));
	scanf("%i %i",&n,&k);
	a.resize(n);
	for(int i=0;i<n;i++)
		scanf("%i %i",&a[i].f.s,&a[i].f.f),a[i].s=i;
	sort(all(a));
	//cout << a << endl;
	calc(0,0);
	pick.clear();
	ostali.clear();
	gen(0,0);
	printf("%i\n",pick.size()+ostali.size()*2);
	for(int i=0;i<k-1;i++)
		printf("%i ",pick[i]+1);
	for(auto p:ostali)
		printf("%i -%i ",p+1,p+1);
	printf("%i\n",pick[k-1]+1);
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
		test();
	}
	return 0;
}