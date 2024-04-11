
// Problem : E. Xum
// Contest : Codeforces - Codeforces Global Round 11
// URL : http://codeforces.com/contest/1427/problem/E
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
template<int D, typename T>struct vec : public vector<vec<D - 1, T>> {template<typename... Args>vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}};
template<typename T>struct vec<1, T> : public vector<T> {vec(int n = 0, T val = T()) : vector<T>(n, val) {}};
template<class T1,class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> istream& operator>>(istream& is,pair<T1,T2>& a) {is>>a.f>>a.s;return is;}
template<class T> istream& operator>>(istream& is,vector<T>& a) {for(auto &p:a)is>>p;return is;}
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
void rd(string&x){cin>>x;}
void rd(char*x){scanf("%s",x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;int i=0;bool neg=false;if(s[0]=='-')neg=true,i++;for(;i<s.size();i++)a=a*10+s[i]-'0';if(neg)a*=-1;return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

const int L=50;
ll lim=1LL<<L;
ll basis[L];
set<ll> ch[L];
vector<ll> in;
bool moze(ll a){
	for(int j=L-1;j>=0;j--){
		if(a&(1LL<<j)){
			if(basis[j]==0)
				return 0;
			a^=basis[j];
		}
	}
	return 1;
}
void add(ll a){
	in.pb(a);
	set<ll> ok;
	ok.insert(a);
	for(int j=L-1;j>=0;j--){
		if(a&(1LL<<j)){
			if(basis[j]==0){
				basis[j]=a;
				ch[j]=ok;
				return;
			}
			a^=basis[j];
			for(auto p:ch[j]){
				if(ok.count(p))
					ok.erase(p);
				else
					ok.insert(p);
			}
		}
	}
}
vector<ll> getOps(ll a){
	set<ll> sta;
	for(int j=L-1;j>=0;j--){
		if(a&(1LL<<j)){
			a^=basis[j];
			for(auto p:ch[j])
				if(sta.count(p))
					sta.erase(p);
				else
					sta.insert(p);
		}
	}
	vector<ll> sol;
	for(auto p:sta)
		sol.pb(p);
	return sol;
}
pair<ll,vector<ll>> getRand(){
	pair<ll,vector<ll>> o;
	for(auto p:in)
		if(rng()%2)
			o.f^=p,o.s.pb(p);
	return o;
}
vector<pair<pair<ll,ll>,int>> ops;
void dodaj(vector<ll> o){
	ll tr=o[0];
	for(int i=1;i<o.size();i++)
		ops.pb({{tr,o[i]},0}),tr^=o[i];
}
int main()
{
	int x;
	scanf("%i",&x);
	add(x);
	pair<ll,vector<ll>> l,r;
	ll nov;
	while(1){
		l=getRand(),r=getRand();
		nov=l.f+r.f;
		while(nov>=lim||moze(nov)){
			l=getRand(),r=getRand();
			nov=l.f+r.f;
		}
		//cout << l << r << nov << endl;
		dodaj(l.s);
		dodaj(r.s);
		ops.pb({{l.f,r.f},1});
		add(nov);
		if(nov==1)
			break;
		if(nov&1){
			if(moze(nov-1)){
				dodaj(getOps(nov-1));
				ops.pb({{nov,nov-1},0});
				break;
			}
		}
		else{
			if(moze(nov+1)){
				dodaj(getOps(nov+1));
				ops.pb({{nov,nov+1},0});
				break;
			}
		}
	}
	printf("%i\n",ops.size());
	for(auto p:ops)
		if(p.s)
			printf("%lld + %lld\n",p.f.f,p.f.s);
		else
			printf("%lld ^ %lld\n",p.f.f,p.f.s);
	return 0;
}