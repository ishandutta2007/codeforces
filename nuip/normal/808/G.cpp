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
const ll MOD=1e9+7;

void Kmp(const string &str,vector<int> &re){
  re.resize(str.size()+1); re[0]=-1;
  int j=-1;
  rep(i,str.size()){
    while(j>=0 && str[i]!=str[j]) j=re[j];
    re[i+1]=++j;
  }
}
int memo[200][112345];
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  string s,t;
  cin>>s>>t;
  int n=s.size();
  int m=t.size();
  vector<int> kmp;
  Kmp(t,kmp);
  rep(i,t.size())reps(c,'a','z'+1){
    if(t[i]==c){
      memo[c][i]=i;
    }else if(kmp[i]<0){
      memo[c][i]=-1;
    }else{
      memo[c][i]=memo[c][kmp[i]];
    }
  }
  //out(kmp,1);
  vector<int> cur(m,-1);
  cur[0]=0;
  rep(i,n){
    vector<int> nxt(m,-1);
    rep(j,m)if(cur[j]>=0){
      if(s[i]=='?'){
	reps(c,'a','z'+1){
	  int tmp=cur[j];
	  int k=memo[c][j];
	  if(++k>=m){
	    ++tmp;
	    k=kmp[k];
	  }
	  MX(nxt[k],tmp);
	}
      }else{
	int tmp=cur[j];
	int k=memo[s[i]][j];
	if(++k>=m){
	  ++tmp;
	  k=kmp[k];
	}
	MX(nxt[k],tmp);
      }
    }
    cur=nxt;
  }
  cout<<*max_element(all(cur))<<endl;
  return 0;
}