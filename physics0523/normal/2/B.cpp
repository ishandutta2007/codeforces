#include<bits/stdc++.h>

using namespace std;

int f(int x,int k){
  int res=0;
  while(x%k==0){
    res++;
    x/=k;
  }
  return res;
}

void sol(int n,vector<vector<int>> &a){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==0 && j==0){continue;}

      int v=1e9;
      if(i){v=min(v,a[i-1][j]);}
      if(j){v=min(v,a[i][j-1]);}
      v+=a[i][j];
      a[i][j]=v;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  vector<vector<int>> p2(n,vector<int>(n));
  vector<vector<int>> p5(n,vector<int>(n));
  int zero=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      if(a[i][j]==0){
        zero++;
        p2[i][j]=1e9;
        p5[i][j]=1e9;
      }
      else{
        p2[i][j]=f(a[i][j],2);
        p5[i][j]=f(a[i][j],5);
      }
    }
  }
  sol(n,p2);
  sol(n,p5);
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << p2[i][j] << ' ';
  //   }cout << '\n';
  // }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << p5[i][j] << ' ';
  //   }cout << '\n';
  // }
  int k=2;
  if(p2[n-1][n-1]>p5[n-1][n-1]){
    p2=p5;
    k=5;
  }
  if(zero>0 && p2[n-1][n-1]>0){
    cout << "1\n";
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(a[i][j]==0){
          for(int cnt=0;cnt<i;cnt++){cout << "D";}
          for(int cnt=0;cnt<j;cnt++){cout << "R";}
          for(int cnt=0;cnt<n-1-i;cnt++){cout << "D";}
          for(int cnt=0;cnt<n-1-j;cnt++){cout << "R";}
          cout << '\n';
          return 0;
        }
      }
    }
  }
  cout << p2[n-1][n-1] << '\n';
  string s;
  int p=n-1,q=n-1;
  while(p>0 || q>0){
    if(p>0 && p2[p-1][q]+f(a[p][q],k)==p2[p][q]){
      s.push_back('D');
      p--;
    }
    else{
      s.push_back('R');
      q--;
    }
  }
  reverse(s.begin(),s.end());
  cout << s << '\n';
  return 0;
}