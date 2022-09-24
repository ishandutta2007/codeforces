#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int n,m;
vector<vector<int> >G;

long long H[1000001],S[1000001],P[1000001];


int main(){
  scanf("%d%d",&n,&m);
  int i,x,y;
  P[0]=97654321;
  for(i=1;i<n;i++)P[i]=P[i-1]*P[0];
  for(i=0;i<m;i++){
    scanf("%d%d",&x,&y);
    x--;y--;
    H[x]+=P[y];
    H[y]+=P[x];
  }
  for(i=0;i<n;i++)S[i]=H[i]+P[i];
  sort(H,H+n);
  sort(S,S+n);
  long long ans,cnt;
  ans=0;
  cnt=1;
  for(i=1;i<n;i++){
    if(H[i-1]==H[i])ans+=cnt++;
    else cnt=1;
  }
  cnt=1;
  for(i=1;i<n;i++){
    if(S[i-1]==S[i])ans+=cnt++;
    else cnt=1;
  }
  cout<<ans<<endl;
  return 0;
}