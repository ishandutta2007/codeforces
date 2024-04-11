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
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
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
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7;

void kmp(const string &str,vector<int> &re){
  re.resize(str.size()+1); re[0]=-1;
  int j=-1;
  rep(i,str.size()){
    while(j>=0 && str[i]!=str[j]) j=re[j];
    re[i+1]=++j;
  }
}

int dp[1123][55][55];
int ep[55][55];

int solve(string s,string a,string b){
	vector<int> A,B;
	kmp(a,A); kmp(b,B);
	// out(A,B,1);
	fill(dp[0][0],dp[1123][0],-MOD);
	dp[0][0][0]=0;
	int n=s.size(),as=a.size(),bs=b.size();
	s+="S"; a+="A"; b+="B";
	rep(i,n+1){
		for(char c:"abcdefghijklmnopqrstuvwxyz"s){
			rep(j,55)rep(k,55) ep[j][k]=dp[i][j][k];
			if(s[i]!='*'){
				c=s[i];
			}
			rrep(j,as+1)rrep(k,bs+1)if(ep[j][k]>-MOD){
				// out(i,j,k,a[j],c,1);
				if(k && b[k]!=c){
					MX(ep[j][B[k]], ep[j][k]-(k==bs));
				}else if(j && a[j]!=c){
					MX(ep[A[j]][k], ep[j][k]+(j==as));
				}else {
					MX(dp[i+1][j+(c==a[j])][k+(c==b[k])], ep[j][k]);
				}
			}
			if(s[i]!='*') break;
		}
	}
	rep(i,n+1)rep(j,as+1)rep(k,bs+1)if(dp[i][j][k]>-MOD) out(i,j,k,dp[i][j][k],1);
	return *max_element(dp[n+1][0],dp[1123][0]);
}

int calc(string s,string a){
	int n=s.size(),m=a.size();
	int re=0;
	rep(i,n-m+1)if(s.substr(i,m)==a) ++re;
	return re;
}

int bf(string s,string a,string b){
	return calc(s,a)-calc(s,b);
}

int main(){
	// auto rnds=
	// 	[](){
	// 		int n=rand()%10+1;
	// 		string s;
	// 		s+=string(1,rand()%2+'a');
	// 		return s;
	// 	};
	// rep(_,100){
	// 	string s=rnds();
	// 	string a=rnds();
	// 	string b=rnds();
	// 	int ans=bf(s,a,b);
	// 	int re=solve(s,a,b);
	// 	if(ans!=re){
	// 		out(s,a,b,ans,re,1); exit(0);
	// 	}
	// }return 0;
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	string s,a,b;
	cin>>s>>a>>b;
	cout<<solve(s,a,b)<<endl;
	// cout<<bf(s,a,b)<<endl;
  return 0;
}