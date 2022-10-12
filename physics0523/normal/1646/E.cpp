#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long res=1;
  int n,m;
  cin >> n >> m;
  vector<bool> fl(20*m+1,false);
  vector<int> f(21,0);
  for(int i=1;i<=20;i++){
    f[i]=f[i-1];
    for(int j=1;j<=m;j++){
      if(!fl[i*j]){
        fl[i*j]=true;
        f[i]++;
      }
    }
  }
  vector<bool> used(n+1,false);
  for(int i=2;i<=n;i++){
    if(used[i]){continue;}
    int cnt=0;
    long long tg=i;
    while(tg<=n){
      used[tg]=true;
      cnt++;
      tg*=i;
    }
    res+=f[cnt];
  }
  cout << res << '\n';
  return 0;
}