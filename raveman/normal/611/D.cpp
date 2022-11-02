#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back

const int mod = 1000000000+7;

int n;
string s;

ll h[5555];
ll st[5555];

int r[5555][5555];
int rs[5555][5555];

ll getH(int pos, int len){
  return h[pos+len-1]-(pos>=0?h[pos-1]:0)*st[len];
}

bool mycmp(int pos,int len){
  int a = 1, b = len, best = len + 1;
  while(a<=b){
    int c = (a+b)>>1;
    if (getH(pos,c) != getH(pos-len,c)) best=c,b=c-1;
    else a=c+1;
  }
  if(best>len) return 0;
  return s[pos+best-1] > s[pos-len+best-1];
  /*REP(i,len){
    if(s[pos+i]!=s[pos-len+i]){
      return s[pos+i]>s[pos-len+i];
    }
  }
  return 0;*/
}

int main(){
#ifdef LocalHost
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif

  cin>>n>>s;
  //  s="";  REP(i,5000)s.pb('1');n=s.size();

  st[0]=1;
  FOR(i,1,5555)st[i]=st[i-1]*10007;
  REP(i,n){
    h[i]=10007*(i?h[i-1]:0)+s[i]-'0'+1;
  }

  for(int i=0;i<s.size();i++){
    for(int len=1;len<=i+1;len++){
      if(s[i-len+1]=='0')continue;
      if (i == len - 1) r[i][len]=1;
      else{
	r[i][len] = rs[i-len][len-1];
	if (i-len-len+1>=0) if (mycmp(i-len+1, len)) r[i][len]=(r[i][len]+r[i-len][len])%mod;
      }
    }
    rs[i][0]=r[i][0];
    for(int j=1;j<=s.size();++j){
      rs[i][j]=rs[i][j-1]+r[i][j];
      if(rs[i][j]>=mod)rs[i][j]-=mod; 
    }
  }
  cout<<rs[s.size()-1][s.size()]<<endl;

#ifdef LocalHost
  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}