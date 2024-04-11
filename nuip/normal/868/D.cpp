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
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;
const int D=18;
using AR=bitset<2<<D>;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<string> ss(n); ss.reserve(200);
	rep(i,n) cin>>ss[i];
	vector<AR> ex; ex.reserve(200);
	for(string s:ss){
		ex.eb(); ex.back().reset();
		ex.back()[1]=1;
		rep(i,s.size()){
			int num=0;
			reps(j,i,s.size()){
				if(j-i>=D) break;
				if(s[j]=='1') num|=1<<(j-i);
				num|=1<<(j-i+1);
				ex.back()[num]=1;
				num^=1<<(j-i+1);
			}
		}
		// out(s,1);
		// reps(i,2,4) cout<<ex.back()[i];cout<<endl;
		// reps(i,4,8) cout<<ex.back()[i];cout<<endl;
		// reps(i,8,16) cout<<ex.back()[i];cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y; --x; --y;
		string tmp=ss[x]+ss[y];
		ss.pb(tmp.substr(0,D));
		if(tmp.size()>D) ss.back()+=tmp.substr(tmp.size()-D);
		ex.pb(ex[x]|ex[y]);
		reps(l,1,min(D,(int)ss[x].size()+1))reps(r,1,min(D,(int)ss[y].size()+1)){
			string s=ss[x].substr((int)ss[x].size()-l);
			s+=ss[y].substr(0,r);
			if(s.size()>D) continue;
			//out(ss[x],ss[y],s,1);
			int num=0;
			rep(i,s.size())if(s[i]=='1') num|=1<<i;
			num|=1<<s.size();
			ex.back()[num]=1;
		}
		int re=0;
		// reps(i,2,4) cout<<ex.back()[i];cout<<endl;
		// reps(i,4,8) cout<<ex.back()[i];cout<<endl;
		// reps(i,8,16) cout<<ex.back()[i];cout<<endl;
		for(;re<D;++re){
			int ng=0;
			reps(i,2<<re,4<<re)if(ex.back()[i]==0) {ng=1; break;}
			if(ng) break;
		}
		cout<<re<<"\n";
	}
  return 0;
}