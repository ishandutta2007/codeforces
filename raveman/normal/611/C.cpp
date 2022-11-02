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

string s[555];

int h[555][555];
int hs[555][555];

int v[555][555];
int vs[555][555];


int main(){
#ifdef LocalHost
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
#endif

  int n,m;
  cin>>n>>m;
  REP(i,n){
    cin>>s[i];
    REP(j,m){
      if(j&&s[i][j]=='.'&&s[i][j-1]=='.')h[i][j]=1;
      if(i&&s[i][j]=='.'&&s[i-1][j]=='.')v[i][j]=1;
    }
  }
  REP(i,n)REP(j,m){
    hs[i][j]=h[i][j]+(i?hs[i-1][j]:0)+(j?hs[i][j-1]:0)-(i&&j?hs[i-1][j-1]:0);
    vs[i][j]=v[i][j]+(i?vs[i-1][j]:0)+(j?vs[i][j-1]:0)-(i&&j?vs[i-1][j-1]:0);
  }
  int q;
  cin>>q;
  REP(i,q){
    int r1,c1,r2,c2;
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    r1--,r2--,c2--,c1--;
    int res = 0;
    res = hs[r2][c2] - hs[r2][c1] - (r1>=0?hs[r1-1][c2]:0) + (r1>=0?hs[r1-1][c1]:0);
    res += vs[r2][c2] - vs[r1][c2] - (c1>=0?vs[r2][c1-1]:0) + (c1>=0?vs[r1][c1-1]:0);
    printf("%d\n",res);
  }

#ifdef LocalHost
  printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
  return 0;
}