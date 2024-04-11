#include<bits/stdc++.h>

using namespace std;

vector<int> A007814={0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0};

int main(){
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(j){cout << ' ';}
      cout << (1<<(2*A007814[j]));
    }cout << '\n';
  }
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n;j++){
      if(j){cout << ' ';}
      cout << (1<<(2*A007814[i]+1));
    }cout << '\n';
  }
  map<int,pair<int,int>> mp;
  int v=0;
  for(int i=0;i<n;i++){
    int w=v;
    for(int j=0;j<n;j++){
      mp[w]={i+1,j+1};
      if(j!=n-1){
        w^=(1<<(2*A007814[j]));
      }
    }
    if(i!=n-1){
      v^=(1<<(2*A007814[i]+1));
    }
  }
  fflush(stdout);
  int z=0;
  for(int i=0;i<k;i++){
    int inp;
    cin >> inp;
    z^=inp;
    cout << mp[z].first << ' ';
    cout << mp[z].second << '\n';
    fflush(stdout);
  }
  return 0;
}