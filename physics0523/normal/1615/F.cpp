#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    a="*"+a;
    b="*"+b;

    vector<long long> dp_pat(2*(n+1),0);
    vector<long long> dp_sol(2*(n+1),0);
    dp_pat[n]=1;

    for(long long i=1;i<=n;i++){
      vector<long long> ndp_pat(2*(n+1),0);
      vector<long long> ndp_sol(2*(n+1),0);
      if(b[i]!='1'){ //b[i]=0
        if(a[i]!='1'){ //a[i]=0
          for(int j=0;j<=2*n+1;j++){
            ndp_pat[j]+=dp_pat[j]; ndp_pat[j]%=mod;
            ndp_sol[j]+=dp_sol[j]; ndp_sol[j]%=mod;
          }
        }
        if(a[i]!='0'){ //a[i]=1
          // put
          int ccol=i%2;
          for(int j=0;j<=2*n+1;j++){
            if(ccol==0){
              if(1<=j && j<=n){
                ndp_pat[j-1]+=dp_pat[j]; ndp_pat[j-1]%=mod;
                ndp_sol[j-1]+=dp_sol[j]; ndp_sol[j-1]%=mod;
                ndp_sol[j-1]+=(mod-i)*dp_pat[j]; ndp_sol[j-1]%=mod;
              }
              else if(n<j){
                ndp_pat[j-1]+=dp_pat[j]; ndp_pat[j-1]%=mod;
                ndp_sol[j-1]+=dp_sol[j]; ndp_sol[j-1]%=mod;
                ndp_sol[j-1]+=i*dp_pat[j]; ndp_sol[j-1]%=mod;
              }
            }
            else{
              if(n<=j && j<=2*n){
                ndp_pat[j+1]+=dp_pat[j]; ndp_pat[j+1]%=mod;
                ndp_sol[j+1]+=dp_sol[j]; ndp_sol[j+1]%=mod;
                ndp_sol[j+1]+=(mod-i)*dp_pat[j]; ndp_sol[j+1]%=mod;
              }
              else if(j<n){
                ndp_pat[j+1]+=dp_pat[j]; ndp_pat[j+1]%=mod;
                ndp_sol[j+1]+=dp_sol[j]; ndp_sol[j+1]%=mod;
                ndp_sol[j+1]+=i*dp_pat[j]; ndp_sol[j+1]%=mod;
              }
            }
          }
        }
      }
      if(b[i]!='0'){ //b[i]=1
        if(a[i]!='1'){ //a[i]=0
          // put
          int ccol=(1-i%2);
          for(int j=0;j<=2*n+1;j++){
            if(ccol==0){
              if(1<=j && j<=n){
                ndp_pat[j-1]+=dp_pat[j]; ndp_pat[j-1]%=mod;
                ndp_sol[j-1]+=dp_sol[j]; ndp_sol[j-1]%=mod;
                ndp_sol[j-1]+=(mod-i)*dp_pat[j]; ndp_sol[j-1]%=mod;
              }
              else if(n<j){
                ndp_pat[j-1]+=dp_pat[j]; ndp_pat[j-1]%=mod;
                ndp_sol[j-1]+=dp_sol[j]; ndp_sol[j-1]%=mod;
                ndp_sol[j-1]+=i*dp_pat[j]; ndp_sol[j-1]%=mod;
              }
            }
            else{
              if(n<=j && j<=2*n){
                ndp_pat[j+1]+=dp_pat[j]; ndp_pat[j+1]%=mod;
                ndp_sol[j+1]+=dp_sol[j]; ndp_sol[j+1]%=mod;
                ndp_sol[j+1]+=(mod-i)*dp_pat[j]; ndp_sol[j+1]%=mod;
              }
              else if(j<n){
                ndp_pat[j+1]+=dp_pat[j]; ndp_pat[j+1]%=mod;
                ndp_sol[j+1]+=dp_sol[j]; ndp_sol[j+1]%=mod;
                ndp_sol[j+1]+=i*dp_pat[j]; ndp_sol[j+1]%=mod;
              }
            }
          }
        }
        if(a[i]!='0'){ //a[i]=1
          for(int j=0;j<=2*n+1;j++){
            ndp_pat[j]+=dp_pat[j]; ndp_pat[j]%=mod;
            ndp_sol[j]+=dp_sol[j]; ndp_sol[j]%=mod;
          }
        }
      }

      dp_pat.swap(ndp_pat);
      dp_sol.swap(ndp_sol);
      // for(int j=0;j<=2*n+1;j++){
      //   cout << dp_pat[j] << ' ';
      // }cout << '\n';
      // for(int j=0;j<=2*n+1;j++){
      //   cout << dp_sol[j] << ' ';
      // }cout << '\n';cout << '\n';
    }
    cout << dp_sol[n] << '\n';
  }
  return 0;
}