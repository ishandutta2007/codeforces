#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 9;
int cnt[N];
int replc[N];//this many cnt[i] elements are replaced

int main(){
  int n;
  cin >> n;
  int p[n];
  int q = n;
  for(int i = 0;i<n;i++){
    cin >> p[i];
    if(cnt[p[i]]==0){
      q--;
    }
    cnt[p[i]]++;
  }
  cout << q << "\n";
  int mex = 1;
  while(cnt[mex]>0)mex++;
  for(int j = 0;j<n;j++){
    if(cnt[p[j]]==1)continue;
    if(replc[p[j]]==0 and mex>p[j]){
      replc[p[j]]=1;
      continue;
    }
    cnt[p[j]]--;
    p[j]=mex;
    cnt[mex]++;
    while(cnt[mex]>0)mex++;
  }
  for(int i = 0;i<n;i++){
    cout << p[i] << " ";
  }
  cout << "\n";
  return 0;
}