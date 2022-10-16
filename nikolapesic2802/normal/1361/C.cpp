// Problem : C. Johnny and Megan's Necklace
// Contest : Codeforces - Codeforces Round #647 (Div. 1) - Thanks, Algo Muse!
// URL : http://codeforces.com/contest/1361/problem/C
// Memory Limit : 512 MB
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

const int N=1<<20;
vector<int> path,st(N);
vector<bool> done(N);
vector<vector<pair<int,int> > > graf(N);
void construct(int tr){
	for(;st[tr]<graf[tr].size();st[tr]++){
		auto p=graf[tr][st[tr]];
		if(!done[p.s/2]){
			done[p.s/2]=1;
			construct(p.f);
			path.pb(p.s^1);
			path.pb(p.s);
		}
	}
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
		scanf("%i %i",&a[i],&b[i]);
	if(n==1){
		printf("%i\n1 2\n",min(20,__builtin_ctz(a[0]^b[0])));
		return 0;
	}
	for(int sol=20;sol>=0;sol--){
		int br=(1<<sol)-1;
		for(int i=0;i<=br;i++)
			graf[i].clear();
		for(int i=0;i<n;i++){
			graf[a[i]&br].pb({b[i]&br,2*i});
			graf[b[i]&br].pb({a[i]&br,2*i+1});
		}
		bool ok=1;
		for(int i=0;i<=br;i++)
			if(graf[i].size()%2)
				ok=0;
		if(!ok)
			continue;
		path.clear();
		fill(all(done),0);
		fill(all(st),0);
		construct(a[0]&br);
		if(path.size()==2*n){
			printf("%i\n",sol);
			for(auto p:path)
				printf("%i ",p+1);
			return 0;
		}
	}
	return 0;
}