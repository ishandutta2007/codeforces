#include<bits/stdc++.h>

using namespace std;

string cvrt(int n,string &a,string &b){
  string res;
  for(int i=0;i<n;i++){
    if(a[i]==b[i]){res.push_back('0');}
    else{res.push_back('1');}
  }
  return res;
}

long long x,y;
long long gap[5005][5005];
long long dp[5005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n >> x >> y;
    string a,b;
    cin >> a >> b;
    string s=cvrt(n,a,b);
    long long cnt=0;
    for(auto &nx : s){
      if(nx=='1'){cnt++;}
    }
    if(cnt%2){cout << "-1\n";continue;}
    if(cnt==0){cout << "0\n";continue;}

    if(x>=y){
      if(cnt>=4){
        cout << (cnt/2)*y << "\n";
        continue;
      }
      else{
        int pt=0;
        for(int i=0;i<n;i++){
          if(s[i]=='1'){pt=i;break;}
        }
        if(s[pt+1]=='0'){
          cout << y << "\n";
          continue;
        }
        else{
          // n >= 5
          cout << min(2*y,x) << "\n";
          continue;
        }
      }
    }
    else{
      // x < y
      vector<long long> pt;
      for(int i=0;i<n;i++){
        if(s[i]=='1'){pt.push_back(i);}
      }
      int sz=pt.size();
      for(int i=0;i<=sz;i++){
        for(int j=0;j<=sz;j++){
          gap[i][j]=1e18;
        }
        dp[i]=1e18;
      }
      for(int i=0;i<=sz;i++){
        long long cur=0;
        gap[i][i]=0;
        for(int j=i+2;j<=sz;j+=2){
          gap[i][j]=gap[i][j-2]+min(y,x*(pt[j-1]-pt[j-2]));
        }
      }
      // for(int i=0;i<=sz;i++){
      //   for(int j=0;j<=sz;j++){
      //     cout << gap[i][j] << " ";
      //   }cout << "\n";
      // }
      for(int j=0;j<=sz;j++){
        for(int i=(j%2);i<=sz;i+=2){
          if((i+1)<=(j-1)){
            gap[i][j]=min(gap[i][j],gap[i+1][j-1]+min(y,x*(pt[j-1]-pt[i])));
          }
        }
      }
      dp[0]=0;
      for(int i=0;i<=sz;i++){
        for(int j=0;j<i;j++){
          if(gap[j][i]>5e17){continue;}
          dp[i]=min(dp[i],dp[j]+gap[j][i]);
        }
      }
      cout << dp[sz] << "\n";
    }
  }
  return 0;
}