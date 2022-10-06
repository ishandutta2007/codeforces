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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	string s,t;
	cin>>n>>s>>t;
	// rep(_,100000){
	// 	string s;
	// 	int n=1000;
	// 	rep(i,n) s+=string(1,'a'+rand()%26);
	// 	t=s; random_shuffle(all(t));
	if(n==1){
		if(s!=t){
			cout<<-1<<endl;
		}else{
			cout<<0<<endl<<endl;
		}
		return 0;
	}
	{
		auto S=s,T=t;
		sort(all(S));
		sort(all(T));
		if(S!=T){
			cout<<-1<<endl;
			return 0;
		}
	}
	int l=(n-1)/2,r=l+1;
	vector<int> re;
	auto fun=[&](int d){
		re.pb(d);
		string A=s.substr(0,n-d);
		string B=s.substr(n-d);
		reverse(all(B));
		s=B+A;
		//out(d,s,1);
	};
	rep(i,n){
		if(s[i]==t[l]){
			fun(n-1-i);
			break;
		}
	}
	//out(re,s,t,1);
	while(1){
		if(r<n){
			fun(r-l);
			int tmp;
			rrep(i,n){
				if(s[i]==t[r]){
					tmp=n-i;
					fun(tmp);
					break;
				}
			}
			fun(n-(r-l)-tmp);
			++r;
		}else break;
		if(l>0){
			--l;
			fun(r-l-1);
			int tmp=-1;
			rrep(i,n){
				if(s[i]==t[l]){
					tmp=n-i;
					fun(tmp);
					break;
				}
			}
			fun(n-(r-l-1)-tmp);
		}else break;
	}
	if(s!=t) fun(n);
	cout<<re.size()<<endl;
	rep(i,re.size()) cout<<re[i]<<" \n"[i+1==re.size()];
	// assert(s==t);
	// assert(re.size()<=6100);
	// }
  return 0;
}