#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,k,w;
  cin >> n >> k >> w;
  string s;
  cin >> s;
  vector<int> s1(n+1,0);
  vector<int> s2(n+1,0);
  for(int i=0;i<n;i++){
    s1[i+1]=s1[i];
    if((i+1)-k >= 0){s2[i+1]=s2[(i+1)-k];}
    if(s[i]=='1'){
      s1[i+1]++;
      s2[i+1]++;
    }
  }

  for(int i=0;i<w;i++){
    int l,r;
    cin >> l >> r;
    int cnt=(r-l+1)/k;
    int put=s2[(l-1)+k*cnt]-s2[l-1];
    int del=(s1[r]-s1[l-1])-put;

    int res=del+(cnt-put);
    // cout << put << " " << del << "\n";
    cout << res << "\n";
  }
  return 0;
}