#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    map<long long,int> dp;
    int r1=0,r2=0;
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      if(s[i]=='K'){r1++;}else{r2++;}
      int g=gcd(r1,r2);
      long long tg=r1/g;
      tg*=1000000007;
      tg+=(r2/g);
      dp[tg]++;
      cout << dp[tg];
    }cout << '\n';
  }
  return 0;
}