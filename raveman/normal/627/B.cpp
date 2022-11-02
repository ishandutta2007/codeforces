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
typedef pair<int,int>pii;
typedef pair<ld,ld>pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)for(int i=(a);i<(b);i++)
#define REP(i,n)FOR(i,0,n)
#define SORT(v)sort((v).begin(),(v).end())
#define UN(v)SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)memset(a,b,sizeof a)
#define pbpush_back

ll s1[1<<20];
ll s2[1<<20];
int n,k,a,b,q;

void addVal(ll* s, int pos, int val){
  pos+=1<<19;
  while(pos){
    s[pos] += val;
    pos>>=1;
  }
}

int getSum(ll* s,int p1,int p2){
  int res = 0;
  p1+=(1<<19);
  p2+=(1<<19);
  while(p1<=p2){
    if(p1&1)res+=s[p1];
    if(!(p2&1))res+=s[p2];
    p1=(p1+1)>>1;
    p2=(p2-1)>>1;
  }
  return res;
}

int main(){
  cin>>n>>k>>a>>b>>q;
  REP(TC,q){
    int type;
    scanf("%d",&type);
    if(type==1){
      int dd,aa;
      scanf("%d %d",&dd,&aa);
      ll a1 = b - s1[dd+(1<<19)];
      a1 = min(a1,(ll)aa);
      addVal(s1,dd,a1);
      ll a2 = a - s2[dd+(1<<19)];
      a2 = min(a2,(ll)aa);
      addVal(s2,dd,a2);
    }else{
      int p;
      scanf("%d",&p);
      printf("%d\n",getSum(s1,1,p-1)+getSum(s2,p+k,n));
    }
  }
  return 0;
}