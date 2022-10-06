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


using namespace std;
typedef __int64 ll;

long c[1001][1001];
ll mod;

void findC(){
  int i,j;
  for(i=0;i<1001;i++){
    c[0][i]=0;
    c[i][0]=1;
  }
  for(i=1;i<1001;i++){
    for(j=1;j<1001;j++){
      if(i==1&&j==1){
        c[i][j]=1;
        continue;
      }
      c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
  }
  return;
}

ll findAns(int all,int times,int ko){
  ll sum=0,re=1;
  if(all==0){
    return 1;
  }
  int i;
  for(i=1;i<=all;i++){
    re=c[all][i];
    for(int j=0;j<i;j++){
      re*=ko;
      re%=mod;
    }
    re*=findAns(all-i,times+1,i);
    sum+=re;
    sum%=mod;
  }
  return sum;
}

int main(){
  findC();
  int i,j;
  int n,k;
  ll sum=0;
  mod=1000000007;
  cin>>n>>k;
  ll ans=findAns(k-1,1,1)*k%mod;
 // cout<<ans<<endl;
  for(i=k+1;i<=n;i++){
    ans*=(n-k);
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}