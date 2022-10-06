#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

int solve(int n,int m){
	if(max(n,m)<=3){
		if(n*m==1){
			cout<<"YES\n1\n";
		}else if(n==m&&m==3){
			cout<<"YES\n";
			cout<<"5 1 3\n";
			cout<<"7 9 4\n";
			cout<<"6 2 8\n";
		}else{
			cout<<"NO\n";
		}
		return 0;
	}
	auto tb=table<int>(n,m,0);
	rep(i,n)rep(j,m) tb[i][j]=i*m+j;
	out(tb,1);
	int f=0;
	if(n<m){
		f=1; swap(n,m);
		auto tmp=table(n,m,0);
		rep(i,n)rep(j,m) tmp[i][j]=tb[j][i];
		tb=tmp;
	}
	vector<int> re;
	rep(i,n)rep(j,m)if((i+j)%2) re.pb(tb[i][j]);
	sort(all(re));
	{
		vector<int> tmp;
		rep(i,n)rep(j,m)if((i+j)%2==0) tmp.pb(tb[i][j]);
		sort(all(tmp));
		if(n==4&&m==2&&f) swap(tmp[0],tmp[1]);
		re.insert(re.end(),all(tmp));
	}
	out(re,1);
	auto check=[&](vv<int> a){
		int n=a.size(),m=a[0].size();
		rep(i,n){rep(j,m) cout<<a[i][j]<<" ";cout<<endl;}
		set<pii> ng;
		rep(i,n)rep(j,m){
			if(i){
				ng.insert(pii(i*m+j,(i-1)*m+j));
				ng.insert(pii((i-1)*m+j,i*m+j));
			}
			if(j){
				if(i*m+j==4) out(i,j,m,1);
				ng.insert(pii(i*m+j,i*m+j-1));
				ng.insert(pii(i*m+j-1,i*m+j));
			}
		}
		rep(i,n)rep(j,m){
			if(i && ng.count(pii(a[i-1][j],a[i][j]))){ out(i-1,i,j,1); return false;}
			if(j && ng.count(pii(a[i][j-1],a[i][j]))){ out(i,j-1,j,1); return false;}
		}
		return true;
	};
	cout<<"YES"<<endl;
	if(f){
		rep(j,m)rep(i,n) cout<<re[i*m+j]+1<<" \n"[i+1==n];
		// auto ret=table(m,n,0);
		// rep(j,m)rep(i,n) ret[j][i]=re[i*m+j];
		// assert(check(ret));
	}else{
		rep(i,n)rep(j,m) cout<<re[i*m+j]+1<<" \n"[j+1==m];
		// auto ret=table(n,m,0);
		// rep(i,n)rep(j,m) ret[i][j]=re[i*m+j];
		// assert(check(ret));
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	//reps(n,1,11)reps(m,1,11){
		solve(n,m);
		//}
  return 0;
}