
// Problem : F. Reverse and Swap
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/F
// Memory Limit : 256 MB
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

const int N=1<<18,L=18;
int n;
vector<int> a(N),le(2*N),ri(2*N);
vector<ll> sum(2*N);
vector<vector<int> > sw(2*N,vector<int>(L+1));
void build(int tr=1,int l=0,int r=N-1){
	if(l==r){
		sum[tr]=a[l];
		return;
	}
	int m=(l+r)>>1;
	le[tr]=2*tr;
	ri[tr]=2*tr+1;
	build(le[tr],l,m);
	build(ri[tr],m+1,r);
	sum[tr]=sum[le[tr]]+sum[ri[tr]];
}
void prop(int tr,int level){
	if(sw[tr][level])
		swap(le[tr],ri[tr]);
	sw[tr][level]=0;
	for(int i=level+1;i<=L;i++)
		sw[le[tr]][i]^=sw[tr][i],sw[ri[tr]][i]^=sw[tr][i],sw[tr][i]=0;
}
void sett(int pos,int x,int tr=1,int l=0,int r=N-1,int level=0){
	if(l==r){
		sum[tr]=x;
		return;
	}
	prop(tr,level);
	int m=(l+r)>>1;
	if(pos<=m)
		sett(pos,x,le[tr],l,m,level+1);
	else
		sett(pos,x,ri[tr],m+1,r,level+1);
	sum[tr]=sum[le[tr]]+sum[ri[tr]];
}
ll s(int qs,int qe,int tr=1,int l=0,int r=N-1,int level=0){
	if(qs>r||qe<l)
		return 0;
	if(qs<=l&&qe>=r)
		return sum[tr];
	prop(tr,level);
	int m=(l+r)>>1;
	return s(qs,qe,le[tr],l,m,level+1)+s(qs,qe,ri[tr],m+1,r,level+1);
}
int main()
{
	int q;
	rd(n,q);
	for(int i=0;i<(1<<n);i++)
		rd(a[i]);
	build();
	for(int i=0;i<q;i++){
		int t,x,k;
		rd(t);
		if(t==1){
			rd(x,k);
			sett(x-1,k);
		}
		if(t==2){
			rd(k);
			k=L-k;
			for(int i=k;i<=L;i++)
				sw[1][i]^=1;
		}
		if(t==3){
			rd(k);
			k=L-k;
			sw[1][k-1]^=1;
		}
		if(t==4){
			rd(x,k);
			printf("%lld\n",s(x-1,k-1));
		}
	}
	return 0;
}