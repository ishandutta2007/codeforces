
// Problem : D. Rsum Review
// Contest : Codeforces - Codeforces Round #639 (Div. 1)
// URL : https://codeforces.com/contest/1344/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
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
vector<int> a;
int n;
ll k;
vector<int> sol;
ll diff(ll a,ll b){
	if(b==-1)
		return LLONG_MAX;
	if(a==b)
		return LLONG_MIN;
	return (b+1)*(a-(b+1)*(b+1))-b*(a-b*b);
}
ll cnt(ll lim){
	ll c=0;
	for(int i=0;i<n;i++){
		int l=0,r=a[i];
		while(l<r){
			int m=(l+r)>>1;
			ll d=diff(a[i],m);
			if(d<=lim)
				r=m;
			else
				l=m+1;
		}
		//printf("%lld %i: %lld %i\n",lim,i,diff(a[i],l),l);
		c+=l;
		sol[i]=l;
	}
	return c;
}
int mx;
void input(){
	scanf("%i %lld",&n,&k);
	a.resize(n);
	sol.resize(n);
	mx=0;
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]),mx=max(mx,a[i]);
}
void gen(){
	n=100000;
	a.resize(n);
	sol.resize(n);
	ll sum=0;
	mx=0;
	for(int i=0;i<n;i++){
		a[i]=rng()%1000000000+1;
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	k=rngll()%sum+1;
}
int main()
{
	//gen();
	input();
	//cout << a << endl;
	ll l=-(ll)mx*mx*3,r=mx;
	while(l<r){
		ll m=(l+r+1)>>1;
		ll c=cnt(m);
		//cout << sol << endl;
		//printf("%lld %lld\n",m,c);
		if(c>=k)
			l=m;
		else
			r=m-1;
	}
	ll top=cnt(l);
	//cout << l << sol << top << endl;
	assert(top>=k);
	for(int i=0;i<n;i++){
		//printf("%i: %lld\n",i,diff(a[i],sol[i]-1));
		if(top!=k&&diff(a[i],sol[i]-1)==l+1)
			top--,sol[i]--;
	}
	assert(top==k);
	for(int i=0;i<n;i++)
		printf("%i ",sol[i]);
	return 0;
}