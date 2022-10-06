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
vector<string> s_p_l_i_t(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while(getline(ss,x,c)) v.emplace_back(x); return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

int cnt[1123456];
vector<int> nums[1123456];
const ll A=1ll*RAND_MAX*RAND_MAX,B=RAND_MAX;

int main(){
  srand(time(0));
  //ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(0);
  int n,m;
  scanf("%d%d",&n,&m);
  vector<ll> hashes(m);
  rep(i,n){
    int t;
    scanf("%d",&t);
    vector<int> vs(t);
    rep(i,t) scanf("%d",&vs[i]), --vs[i];
    //cout<<vs;
    for(int x:vs) ++cnt[x];
    vector<int> tar;
    ll hash=A*rand()+B*rand()+rand();
    for(int x:vs)if(cnt[x]){
	//out(x,cnt[x],1);
	tar.pb(cnt[x]);
	nums[cnt[x]].pb(x);
	cnt[x]=0;
      }
    for(int x:tar)if(nums[x].size()){
	//out(x,nums[x]);
	for(int i:nums[x]) hashes[i]^=hash*x;
	nums[x].clear();
      }
  }
  unordered_map<ll,int> cnt;
  for(ll x:hashes) ++cnt[x];
  ll re=1;
  for(auto p:cnt)rep(i,p.Y) (re*=i+1)%=MOD;
  printf("%I64d\n",re);
  return 0;
}
//35181 150961663