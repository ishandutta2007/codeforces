#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){cin >> a[i];}
  while(1){
    bool fl=false;
    for(int i=0;i<n;i++){if(a[i]%2==1){fl=true;}}
    if(fl){break;}
    for(int i=0;i<n;i++){a[i]/=2;}
  }
  int sig=0;
  for(int i=0;i<n;i++){sig+=a[i];}
  if(sig%2==1){cout << "0\n";return 0;}
  vector<bool> dp(262144,false);
  dp[0]=true;
  for(int i=0;i<n;i++){
    for(int j=262143;j>=0;j--){
      if(!dp[j]){continue;}
      if((j+a[i])>=262144){continue;}
      dp[j+a[i]]=true;
    }
  }
  if(dp[sig/2]){
    cout << "1\n";
    for(int i=0;i<n;i++){
      if(a[i]%2){
        cout << i+1 << '\n';
        return 0;
      }
    }
  }
  else{cout << "0\n";return 0;}
  return 0;
}