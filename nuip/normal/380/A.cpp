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
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;
typedef pair<ll,ll> P;


ll stages[112345][3],n,m,ans[112345],a[112345];
priority_queue<P> ind;

int main(){
  ll i,j,tmp,r,k;
  scanf("%I64d",&n);
  for(i=0;i<n;i++){
    scanf("%I64d %I64d",&stages[i][0],&stages[i][1]);
    if(stages[i][0]==2)
      scanf("%d",&stages[i][2]);
  }

  r=i=0;
  for(i=0;i<n&&r<100000;i++){
    if(stages[i][0]==1){
      a[r++]=stages[i][1];
    }else{
      for(j=0;j<stages[i][2];j++){
          if(r>=100000)break;
        for(k=0;k<stages[i][1];k++){
          if(r>=100000)break;
          a[r++]=a[k];
        }
      }
    }
  }
  //solve(0,0);
  ll ans,rs[112345];
  rs[0]=0;
  for(i=0;i<n;i++){
    if(stages[i][0]==1){
      rs[i+1]=rs[i]+1;
    }else{
      rs[i+1]=rs[i]+stages[i][1]*stages[i][2];
    }
  }
  
  scanf("%I64d",&m);
  r=0;
  for(i=0;i<m;i++){
    scanf("%I64d",&tmp);
   // ind.push(P(tmp,i));
    tmp--;
    if(tmp<100000){
      ans=a[tmp];
    }else{
      while(rs[r]<tmp)r++;
      r--;
      ans=stages[r][0]==1?stages[r][1]:a[(tmp-rs[r])%stages[r][1]];
    }
    printf("%I64d%c",ans,(i==m-1?'\n':' '));
  }
  return 0;
}