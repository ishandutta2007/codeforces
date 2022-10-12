#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<string> s(n);
  vector<vector<int>> h(n+1,vector<int>(n+1,0));
  vector<vector<int>> w(n+1,vector<int>(n+1,0));
  for(int i=0;i<n;i++){cin >> s[i];}

  for(int i=0;i<n;i++){
    int c=0;
    for(int j=0;j<n;j++){
      if(s[i][j]=='.'){c++;}else{c=0;}
      if(c>=k){h[i][j-k+1]++;h[i][j+1]--;}
    }
    for(int j=1;j<n;j++){h[i][j]+=h[i][j-1];}
  }
  for(int j=0;j<n;j++){
    int c=0;
    for(int i=0;i<n;i++){
      if(s[i][j]=='.'){c++;}else{c=0;}
      if(c>=k){w[i-k+1][j]++;w[i+1][j]--;}
    }
    for(int i=1;i<n;i++){w[i][j]+=w[i-1][j];}
  }
  int p=0,q=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(h[p][q]+w[p][q]<h[i][j]+w[i][j]){p=i;q=j;}
    }
  }
  cout << p+1 << ' ' << q+1 << '\n';
  return 0;
}