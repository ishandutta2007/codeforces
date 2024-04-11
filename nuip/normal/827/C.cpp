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

int id[200];

const int nn=100345;
int bits[4][11][10][nn+1];

int sum(int *bit,int i){ ++i;
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

int sum(int *bit,int l,int r){
  return sum(bit,r-1)-sum(bit,l-1);
}

void add(int *bit,int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

void add(int c,int ind,int x){
  reps(j,1,11) add(bits[c][j][ind%j],ind,x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  rep(i,4) id["ATGC"[i]]=i;
  string s;
  cin>>s;
  rep(i,s.size()) add(id[s[i]],i,1);
  int q;
  cin>>q;
  while(q--){
    int t;
    cin>>t;
    if(t==1){
      int ind;
      char c;
      cin>>ind>>c; --ind;
      add(id[s[ind]],ind,-1);
      s[ind]=c;
      add(id[s[ind]],ind,1);
    }else{
      int l,r;
      string t;
      cin>>l>>r>>t; --l;
      int re=0;
      int m=t.size();
      rep(j,m) re+=sum(bits[id[t[j]]][m][(l+j)%m],l,r);
      cout<<re<<"\n";
    }
  }
  return 0;
}