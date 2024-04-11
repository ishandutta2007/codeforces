#include<bits/stdc++.h>
#define X first
#define Y second
#define pb emplace_back
#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define EFOR(i,a,b) for(int (i)=(a);i<=(b);++(i))
#define rep(X,Y) for(int (X) = 0;(X) < (Y);++(X))
#define REP rep
#define rrep(X,Y) for( int (X) =(Y)-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef ll LL;
typedef pii PII;
typedef pll PLL;
const ll MOD=1e9+7;

#define rall(X) (X).rbegin(),(X).rend()
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define reps(X,S,Y) for(int (X)=S;(X)<(Y);++(X))
#define rreps(X,S,Y) for(int (X) =(Y)-1; (X)>=(S);--(X))
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}

int g[11][11];

int main(){
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(0);
  int n;
  cin>>n;
  rep(i,n)rep(j,n) cin>>g[i][j];
  rep(i,n) g[i][i]=1;
  rep(k,n)rep(i,n)rep(j,n) g[i][j]|=g[i][k]*g[k][j];
  vector<int> cc(n);
  rep(i,n)rep(j,n)if(g[i][j] && g[j][i]){
    cc[i]=j;
    break;
  }
  int N=18,m=3;
  string one=string(N,'#');
  string zero=string(N,'.');
  vector<string> base(3,one);
  rep(i,n) base[2][i*2]='.';
  cout<<N<<" "<<m<<" "<<27<<endl;
  vector<int> ex(n,1);
  rrep(_,9){
    int v=-1;
    rep(i,n)if(ex[i]){
      int ng=0;
      rep(j,n)if(ex[j] && g[j][i] && !g[i][j]) ng=1;
      if(ng) continue;
      v=i;
      break;
    }
    if(v<0){
      rep(_,3) cout<<zero<<"\n"<<zero<<"\n"<<zero<<"\n"<<"\n";
      continue;
    }
    for(string s:base) cout<<s<<"\n"; cout<<"\n";

    cout<<zero<<endl;
    string s=one;
    rep(i,n)if(g[v][i]) s[i*2]='.';
    cout<<s<<endl;
    s=base[2];
    auto b=base;
    rep(i,n)if(cc[i]==v){
      s[i*2]='1'+i;
      b[2][i*2]='#';
    }
    cout<<s<<endl<<endl;

    for(string s:b) cout<<s<<"\n"; cout<<"\n";

    rep(i,n)if(cc[i]==v) ex[i]=0;
  }
  return 0;
}