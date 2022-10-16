
// Problem : F. Network Coverage
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/F
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

bool test(){
	int n;
	scanf("%i",&n);
	vector<int> a(n),b(n),c(n);
	vector<ll> in(n,-1),of(n);
	ll aa=0,bb=0;
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]),aa+=a[i];
	for(int i=0;i<n;i++)
		scanf("%i",&b[i]),bb+=b[i];
	if(aa>bb)
		return 0;
	for(int i=0;i<n;i++)
		if(a[i]>b[i]+b[(i-1+n)%n])
			return 0;
	ll flow=0;
	for(int i=0;i<n;i++){
		int t=min(a[i],b[i]);
		a[i]-=t;
		b[i]-=t;
		c[i]=t;
		flow+=t;
	}
	multiset<ll> vals;
	ll off=0;
	int tr=1;
	for(int i=0;i<n&&flow!=aa;i++){
		//cout << i << vals << off << "   " << tr << "  " << flow << endl;
		//cout << c << endl;
		while(b[i]!=0&&flow!=aa){
			//printf("%i %i %i\n",b[i],tr,a[tr]);
			while(a[tr]==0&&flow!=aa){
				//printf("%i!\n",tr);
				in[tr]=c[tr]+off;
				of[tr]=off;
				vals.insert(c[tr]+off);
				tr=(tr+1)%n;
			}
			if(vals.empty()){
				int cnt=min({a[tr],b[i]});
				if(cnt==0){
					break;
				}
				off+=cnt;
				a[tr]-=cnt;
				b[i]-=cnt;
				flow+=cnt;
				continue;
			}
			int mn=(*vals.begin())-off;
			int cnt=min({a[tr],mn,b[i]});
			if(cnt==0){
				break;
			}
			off+=cnt;
			a[tr]-=cnt;
			b[i]-=cnt;
			flow+=cnt;
		}
		if(in[(i+1)%n]!=-1){
			c[(i+1)%n]-=off-of[(i+1)%n];
		}
		if(vals.empty()){
			assert(tr==(i+1)%n);
			tr=(tr+1)%n;
		}
		else{
			vals.erase(vals.find(in[(i+1)%n]));
		}
	}
	return flow==aa;
}
int main()
{
	int t;
	scanf("%i",&t);
	vector<bool> vals;
	while(t--)
		vals.pb(test());
	for(auto p:vals)
		printf(p?"YES\n":"NO\n");
	return 0;
}