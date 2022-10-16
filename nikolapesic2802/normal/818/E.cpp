
// Problem : E. Card Game Again
// Contest : Codeforces - Educational Codeforces Round 24
// URL : https://codeforces.com/problemset/problem/818/E
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

int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	if(k==1){
		printf("%lld\n",(ll)n*(n+1)/2);
		return 0;
	}
	vector<pair<int,int> > f;
	for(int i=2;i*i<=k;i++){
		if(k%i==0){
			int cnt=0;
			while(k%i==0)
				k/=i,cnt++;
			f.pb({i,cnt});
		}
	}
	if(k!=1)
		f.pb({k,1});
	int m=f.size();
	vector<int> cnt(m);
	vector<int> a(n);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	int l=0;
	int cntOk=0;
	auto dodaj=[&](int i){
		int x=a[i];
		for(int j=0;j<m;j++){
			while(x%f[j].f==0){
				if(cnt[j]==f[j].s-1)
					cntOk++;
				cnt[j]++;
				x/=f[j].f;
			}
		}
	};
	auto oduzmi=[&](int i){
		int x=a[i];
		for(int j=0;j<m;j++){
			while(x%f[j].f==0){
				if(cnt[j]==f[j].s)
					cntOk--;
				cnt[j]--;
				x/=f[j].f;
			}
		}
	};
	ll sol=0;
	for(int i=0;i<n;i++){
		dodaj(i);
		while(cntOk==m){
			oduzmi(l);
			l++;
			if(cntOk==m)
				continue;
			l--;
			dodaj(l);
			break;
		}
		if(cntOk==m)
			sol+=l+1;
	}
	printf("%lld\n",sol);
	return 0;
}