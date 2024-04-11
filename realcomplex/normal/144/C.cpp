#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 9;
int cnt[N][26];
int v[N][26];

int main(){
  string a,b;
  cin >> a >> b;
  for(int i = 0;i<a.size();i++)
    if(a[i]!='?')
      cnt[i+1][a[i]-97]++;
  for(int j = 0;j<b.size();j++)
      v[j+1][b[j]-97]++;
  for(int i = 1;i<N;i++){
    for(int j = 0;j<26;j++)
      cnt[i][j]+=cnt[i-1][j],v[i][j]+=v[i-1][j];
  }
  int l = -1;
  int ans = 0;
  for(int i = b.size();i<=a.size();i++){
    ans++;
    l++;
    for(int j = 0;j<26;j++){
       if(cnt[i][j]-cnt[l][j]>v[b.size()][j]){
         ans--;
         break;
       }
    }
  }
  cout << ans << "\n";
  return 0;
}