#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    for(int i=0;i<2;i++){
      for(int j=0;j<n;j++){
        cin >> a[i][j];
        if(a[i][j]==0){a[i][j]=-2e9;}
      }
    }
    int res=2e9;

    int st=0,fi=(n+1)/2;
    while(st<=fi){
      int te=(st+fi)/2;
      int bd=2*te;
      int cur=-1;
      for(int i=0;i<bd;i++){
        if(i%2){
          cur=max(cur+1,a[1][i]+1);
          cur=max(cur+1,a[0][i]+1);
        }
        else{
          cur=max(cur+1,a[0][i]+1);
          cur=max(cur+1,a[1][i]+1);
        }
      }

      bool bn=false;
      for(int i=bd;i<n;i++){
        if(cur+1 < a[0][i]+1){
          bn=true;
        }
        cur=max(cur+1,a[0][i]+1);
      }
      for(int i=n-1;i>=bd;i--){
        if(cur+1 < a[1][i]+1){
          bn=true;
        }
        cur=max(cur+1,a[1][i]+1);
      }
      res=min(res,cur);
      if(bn){st=te+1;}
      else{fi=te-1;}
    }

    st=1;fi=(n+1)/2;
    while(st<=fi){
      int te=(st+fi)/2;
      int bd=2*te-1;
      int cur=-1;
      for(int i=0;i<bd;i++){
        if(i%2){
          cur=max(cur+1,a[1][i]+1);
          cur=max(cur+1,a[0][i]+1);
        }
        else{
          cur=max(cur+1,a[0][i]+1);
          cur=max(cur+1,a[1][i]+1);
        }
      }

      bool bn=false;
      for(int i=bd;i<n;i++){
        if(cur+1 < a[1][i]+1){
          bn=true;
        }
        cur=max(cur+1,a[1][i]+1);
      }
      for(int i=n-1;i>=bd;i--){
        if(cur+1 < a[0][i]+1){
          bn=true;
        }
        cur=max(cur+1,a[0][i]+1);
      }
      res=min(res,cur);
      if(bn){st=te+1;}
      else{fi=te-1;}
    }
    cout << res << "\n";
  }
  return 0;
}