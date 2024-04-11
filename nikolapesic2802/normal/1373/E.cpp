
// Problem : E. Sum of Digits
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/E
// Memory Limit : 512 MB
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

int sum(int x){
	int s=0;
	while(x)
		s+=x%10,x/=10;
	return s;
}
int sum(int x,int k){
	int s=0;
	for(int i=0;i<=k;i++)
		s+=sum(x+i);
	return s;
}
int mex=0;
ll solve(int n,int k){
	if(sum(0,k)>n)
			return -1;
	if(k==0){
		ll sol=0;
		if(n%9)
			sol+=n%9;
		for(int i=0;i<n/9;i++)
			sol=sol*10+9;
		return sol;
	}
	if(k==1){
		if(n==1)
			return 0;
		int mn=INT_MAX;
		for(int br=0;br<10;br++){
			int nn=n-br*9;
			if(nn<=0)
				break;
			string tr(br,'9');
			if(nn==1){
				if(tr.size()<10)
					mn=min(mn,stoi(tr));
				break;
			}
			nn--;
			if(nn&1)
				continue;
			//printf("%i: %i\n",br,nn);
			nn/=2;
			int d=min(8,nn);
			string ss;
			if(d){
				ss+='0'+d;
				nn-=d;
				tr=ss+tr;
			}
			while(nn>8){
				tr="9"+tr;
				nn-=9;
			}
			if(nn){
				string aa;
				aa+='0'+nn;
				tr=aa+tr;
			}
			if(tr.size()<10)
				mn=min(mn,stoi(tr));
		}
		if(mn==INT_MAX)
			mn=-1;
		return mn;
	}
	for(int sol=0;;sol++){
		if(sum(sol,k)==n)
			return sol;
		if(k!=2&&sol>100000)
			return -1;
		if(k>5&&sol>20000)
			return -1;
		if(sol>699997)
			return -1;
	}
}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--){
		int n,k;
		scanf("%i %i",&n,&k);
		printf("%lld\n",solve(n,k));
	}
	return 0;
}