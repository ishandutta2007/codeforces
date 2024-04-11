
// Problem: C. Complete the MST
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int N=2e5+5;
vector<set<int>> has(N);
vector<int> p(N);
int find(int tr){return tr==p[tr]?tr:p[tr]=find(p[tr]);}
void merge(int a,int b){p[find(a)]=find(b);}

int main()
{
	iota(all(p),0);
	int n=ri(),m=ri();
	vector<pair<int,pair<int,int>>> know(m);
	int xr=0;
	for(int i=0;i<m;i++){
		rd(know[i].s.f,know[i].s.s,know[i].f);
		know[i].s.f--;
		know[i].s.s--;
		int a=know[i].s.f;
		int b=know[i].s.s;
		has[a].insert(b);
		has[b].insert(a);
		xr^=know[i].f;
	}
	sort(all(know));
	vector<int> my;
	vector<int> unknow;
	for(int i=0;i<n;i++)
		unknow.pb(i);
	int cntMerge=0;
	while(unknow.size()){
		int i=unknow.back();
		unknow.pop_back();
		my.pb(i);
		while(my.size()){
			int tr=my.back();
			my.pop_back();
			vector<int> er;
			for(auto p:unknow){
				if(!has[tr].count(p)){
					merge(i,p);
					cntMerge++;
					my.pb(p);
				}
				else
					er.pb(p);
			}
			unknow=er;
		}
	}
	if(cntMerge!=(ll)n*(n-1)/2-m){
		ll cost=0;
		for(auto p:know){
			if(find(p.s.f)!=find(p.s.s)){
				merge(p.s.f,p.s.s);
				cost+=p.f;
			}
		}
		printf("%lld\n",cost);
		return 0;
	}
	assert(n<=650);
	vector<pair<int,int>> dont;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!has[j].count(i)){
				dont.pb({i,j});
			}
		}
	}
	assert(dont.size()<n);
	ll best=LLONG_MAX;
	for(int i=0;i<dont.size();i++){
		for(int i=0;i<n;i++)
			p[i]=i;
		for(int j=0;j<dont.size();j++)
			if(j!=i)
				merge(dont[j].f,dont[j].s);
		bool added=0;
		ll cost=0;
		for(auto p:know){
			if(p.f>xr){
				if(find(dont[i].f)!=find(dont[i].s)){
					merge(dont[i].f,dont[i].s);
					cost+=xr;
					added=1;
				}
			}
			if(find(p.s.f)!=find(p.s.s)){
				merge(p.s.f,p.s.s);
				cost+=p.f;
			}
		}
		if(!added){
			if(find(dont[i].f)!=find(dont[i].s)){
				merge(dont[i].f,dont[i].s);
				cost+=xr;
			}
		}
		best=min(best,cost);
	}
	printf("%lld\n",best);
	return 0;
}