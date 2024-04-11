#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 1072114514
#define MA 10000005

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  vector<int> hv(MA,1);
  vector<bool> fl(MA,false);
  for(int i=2;i<MA;i++){
    if(fl[i]){continue;}
    for(int j=i;j<MA;j+=i){
      fl[j]=true;
      int cnt=0,cv=j;
      while(cv%i==0){cv/=i;cnt++;}
      if(cnt%2==1){hv[j]*=i;}
    }
  }

  int t;
  cin >> t;
  vector<int> bk(MA,0);
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      a[i]=hv[a[i]];
    }
    
    vector<vector<int>> jump(n,vector<int>(k+1));
    for(int i=0;i<=k;i++){
      int st=0,fi=0,pt=0;
      for(int j=0;j<n;j++){bk[a[j]]=0;}
      while(1){
        if(pt>i){
          jump[st][i]=fi-1;
          if(bk[a[st]]>=2){pt--;}
          bk[a[st]]--;
          st++;
        }
        else if(fi==n){
          while(st<n){jump[st][i]=n;st++;}
          break;
        }
        else{
          bk[a[fi]]++;
          if(bk[a[fi]]>=2){pt++;}
          fi++;
        }
      }
    }

    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<=k;j++){
        if(j){dp[i][j]=min(dp[i][j],dp[i][j-1]);}
        for(int d=0;j+d<=k;d++){
          dp[jump[i][d]][j+d]=min(dp[jump[i][d]][j+d],dp[i][j]+1);
        }
      }
    }
    int res=inf;
    for(int i=0;i<=k;i++){res=min(dp[n][i],res);}
    cout << res << '\n';
  }
  return 0;
}