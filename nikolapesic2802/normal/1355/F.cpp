// Problem : F. Guess Divisors Count
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int N=31623,my=0;
const ll big=1e18;
int d[N];
int X;
int ask(ll a){
	if(my)
		return gcd(a,X);
	printf("? %lld\n",a);
	fflush(stdout);
	int o;
	scanf("%i",&o);
	return o;
}
vector<int> primes;
void init(){
	for(int i=2;i<N;i++){
		if(d[i]==0){
			primes.pb(i);
			for(int j=i;j<N;j+=i)
				d[j]=i;
		}
	}
}
int numDivs(){
	int cnt=0;
	for(int i=1;i*i<=X;i++){
		if(X%i==0){
			cnt++;
			if(X/i!=i)
				cnt++;
		}
	}
	return cnt;
}
bool answer(int a){
	if(my){
		int d=numDivs();
		//printf("My ans: %i, real: %i\n",a,d);
		return abs(d-a)<=7||(d<=2*a&&a<=2*d);
	}
	printf("! %i\n",a);
	fflush(stdout);
	return 1;
}
void solve(){
	if(primes.empty())
		init();
	int n=primes.size();
	vector<int> cnt(n,-1);
	int stigao=0;
	set<int> active;
	for(int o=0;o<20;o++){
		ll tr=1;
		vector<int> trQ;
		for(auto p:active){
			cnt[p]++;
			ll add=pow(primes[p],cnt[p]);
			if(big/add<tr)
				continue;
			trQ.pb(p);
			tr*=add;
		}
		for(;stigao<n;stigao++){
			ll add=primes[stigao];
			if(big/add<tr)
				break;
			trQ.pb(stigao);
			active.insert(stigao);
			cnt[stigao]=1;
			tr*=add;
		}
		int ans=ask(tr);
		for(auto p:trQ){
			ll add=pow(primes[p],cnt[p]);
			if(ans%add==0)
				continue;
			active.erase(p);
			cnt[p]--;
		}
	}
	int ans=1;
	for(int i=0;i<stigao;i++)
		ans*=cnt[i]+1;
	ans*=2;
	if(!answer(ans)){
		printf("Error! %i\n",X);
		exit(0);
	}
}
void myplay(){
	scanf("%i",&X);
	solve();
}
void stress(){
	int cnt=0;
	while(true){
		X=rng()%1000000000+1;
		solve();
		cnt++;
		if(cnt%10000==0)
			printf("%i!\n",cnt);
	}
}
int main()
{
	//stress();
	int t;
	scanf("%i",&t);
	while(t--){
		if(my)
			myplay();
		else
			solve();
	}
	return 0;
}