// Problem : D. Yui and Mahjong Set
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/contest/1336/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define D(x) cerr << #x << " is " << (x) << "\n";
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

const int N=105;
bool znam[N];
int o[N],v[N];
struct val{
	int i,off;
	int get(){
		assert(znam[i]);
		return v[i]-o[i]+off;
	}
};
struct eq{
	int c;
	vector<pair<val,val> > vals;
	bool done;
};
vector<eq> sve;
bool zakljuci(){
	for(auto &p:sve){
		if(p.done)
			continue;
		int koji=-1,of=-1;
		for(auto d:p.vals){
			if(!znam[d.f.i]){
				if(koji!=-1&&koji!=d.f.i){
					koji=-1;
					break;
				}
				koji=d.f.i;
				of=d.f.off;
			}
			if(!znam[d.s.i]){
				if(koji!=-1&&koji!=d.s.i){
					koji=-1;
					break;
				}
				koji=d.s.i;
				of=d.s.off;
			}
		}
		//printf("%i %i !!!!\n",koji,of);
		if(koji==-1){
			if(of==-1)
				p.done=1;
			continue;
		}
		int c=p.c;
		int uz=0;
		for(auto d:p.vals){
			if(d.f.i==koji){
				uz+=d.s.get();
			}
			if(d.s.i==koji){
				uz+=d.f.get();
			}
			if(d.f.i!=koji&&d.s.i!=koji){
				c-=d.f.get()*d.s.get();
			}
		}
		if(uz==0){
			p.done=1;
			continue;
		}
		//printf("%i %i  %i %i\n",koji,of,c,uz);
		assert(c>=0&&c%uz==0);
		v[koji]=c/uz-of+o[koji];
		znam[koji]=1;
		p.done=1;
		return 1;
	}
	return 0;
}
int n;
int a,b;
void addEq(int change,int i){
	eq novi;
	novi.c=change;
	novi.done=0;
	if(i>1)
		novi.vals.pb({{i-2,o[i-2]},{i-1,o[i-1]}});
	if(i>0&&i<n-1)
		novi.vals.pb({{i+1,o[i+1]},{i-1,o[i-1]}});
	if(i<n-2)
		novi.vals.pb({{i+1,o[i+1]},{i+2,o[i+2]}});
	/*printf("Equation: %i\n",change);
	for(auto p:novi.vals)
		printf("%i %i   %i %i\n",p.f.i,p.f.off,p.s.i,p.s.off);*/
	sve.pb(novi);
}
void solve(){
	while(zakljuci());
}
int nC3(int n){
	return n*(n-1)*(n-2)/2/3;
}
int myVal[N];
int calcA(){
	int aa=0;
	for(int i=0;i<n;i++)
		aa+=nC3(myVal[i]);
	return aa;
}
int calcB(){
	int bb=0;
	for(int i=0;i<n-2;i++)
		bb+=myVal[i]*myVal[i+1]*myVal[i+2];
	return bb;
}
pair<int,int> my(int i){
	myVal[i]++;
	int aa=calcA(),bb=calcB();
	pair<int,int> ok={aa-a,bb-b};
	a=aa;
	b=bb;
	o[i]++;
	return ok;
}
int used=0;
pair<int,int> q(int i){
	used++;
	//return my(i);
	printf("+ %i\n",i+1);
	fflush(stdout);
	int aa,bb;
	scanf("%i %i",&aa,&bb);
	pair<int,int> ok={aa-a,bb-b};
	a=aa;
	b=bb;
	o[i]++;
	return ok;
}
map<int,int> diff;
pair<int,int> doit(int i){
	pair<int,int> a=q(i);
	addEq(a.s,i);
	if(a.f||o[i]>1){
		v[i]=diff[a.f];
		znam[i]=1;
	}
	else{
		if(znam[i])
			v[i]++;
	}
	//printf("%i: %i\n",i,v[i]-o[i]);
	solve();
	return a;
}
int main()
{
	diff[0]=2;
	for(int i=3;i<N;i++){
		int a=nC3(i)-nC3(i-1);
		assert(diff.find(a)==diff.end());
		diff[a]=i;
	}
	scanf("%i",&n);
	scanf("%i %i",&a,&b);
	for(int i=n-2;i>=2;i--)
		doit(i);
	int prvi=doit(0).s;
	doit(1);
	int drugi=doit(0).s;
	if(!znam[2]){
		znam[2]=1;
		v[2]=drugi-prvi;
	}
	solve();
	/*for(int i=0;i<n;i++){
		if(!znam[i]&&used<n){
			doit(i);
		}
	}*/
	printf("! ");
	for(int i=0;i<n;i++)
		printf("%i ",v[i]-o[i]);
	printf("\n");
	return 0;
}