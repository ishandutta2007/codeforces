
// Problem : E2. Reading Books (hard version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : http://codeforces.com/contest/1374/problem/E2
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
int ri(){int x;scanf("%i",&x);return x;}
void rd(int&x){scanf("%i",&x);}
void rd(long long&x){scanf("%lld",&x);}
void rd(double&x){scanf("%lf",&x);}
void rd(long double&x){scanf("%Lf",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&p:x)rd(p);}
template<typename C,typename...T>void rd(C&a,T&...args){rd(a);rd(args...);}
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

int main()
{
	int n=ri(),m=ri(),k=ri();
	vector<pair<int,int> > aa,bb,both,other;
	for(int i=0;i<n;i++){
		int t=ri(),a=ri(),b=ri();
		if(a&&b){
			both.pb({t,i});
			continue;
		}
		if(a)
			aa.pb({t,i});
		if(b)
			bb.pb({t,i});
		if(!a&&!b)
			other.pb({t,i});
	}
	sort(all(aa));
	sort(all(bb));
	sort(all(both));
	sort(all(other));
	vector<pair<int,int>> aaa=aa,bbb=bb;
	for(int i=1;i<aa.size();i++)
		aa[i].f+=aa[i-1].f;
	for(int i=1;i<bb.size();i++)
		bb[i].f+=bb[i-1].f;
	for(int i=1;i<both.size();i++)
		both[i].f+=both[i-1].f;
	aaa.pb({INT_MAX,INT_MAX});
	bbb.pb({INT_MAX,INT_MAX});
	other.pb({INT_MAX,INT_MAX});
	auto getVal=[&](int num){
		int ostalo=m-num;
		int treba=max(0,k-num);
		int price=0;
		if(num)
			price+=both[num-1].f;
		//printf("%i %i %i    !\n",treba,aa.size(),bb.size());
		if(treba>aa.size()||treba>bb.size())
			return INT_MAX;
		if(treba)
			price+=aa[treba-1].f+bb[treba-1].f;
		ostalo-=2*treba;
		if(ostalo<0)
			return INT_MAX;
		//printf("%i %i %i!\n",num,ostalo,price);
		int le=treba,ri=treba,o=0;
		for(int i=0;i<ostalo;i++){
			int mn=min({aaa[le].f,bbb[ri].f,other[o].f});
			if(mn==INT_MAX)
				return INT_MAX;
			if(aaa[le].f==mn){
				price+=aaa[le].f;
				le++;
				continue;
			}
			if(bbb[ri].f==mn){
				price+=bbb[ri].f;
				ri++;
				continue;
			}
			if(other[o].f==mn){
				price+=other[o].f;
				o++;
				continue;
			}
		}
		return price;
	};
	int l=0,r=min((int)both.size(),m);
	//for(int i=l;i<=r;i++)printf("%i: %i\n",i,getVal(i));
	while(l<r){
		int m=(l+r)>>1;
		if(getVal(m)<getVal(m+1))
			r=m;
		else
			l=m+1;
	}
	if(getVal(l)==INT_MAX){
		printf("-1\n");
		return 0;
	}
	printf("%i\n",getVal(l));
	int num=l;
	int ostalo=m-num;
	int treba=max(0,k-num);
	int price=0;
	if(num){
		for(int i=0;i<num;i++)
			printf("%i ",both[i].s+1);
	}
	if(treba){
		for(int i=0;i<treba;i++)
			printf("%i %i ",aa[i].s+1,bb[i].s+1);
	}
	ostalo-=2*treba;
	int le=treba,ri=treba,o=0;
	for(int i=0;i<ostalo;i++){
		int mn=min({aaa[le].f,bbb[ri].f,other[o].f});
		if(mn==INT_MAX)
			return INT_MAX;
		if(aaa[le].f==mn){
			printf("%i ",aaa[le].s+1);
			price+=aaa[le].f;
			le++;
			continue;
		}
		if(bbb[ri].f==mn){
			printf("%i ",bbb[ri].s+1);
			price+=bbb[ri].f;
			ri++;
			continue;
		}
		if(other[o].f==mn){
			printf("%i ",other[o].s+1);
			price+=other[o].f;
			o++;
			continue;
		}
	}
	printf("\n");
	return 0;
}