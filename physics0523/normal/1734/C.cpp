#include<bits/stdc++.h>

using namespace std;

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
    s="-"+s;
    long long res=0;
    vector<int> fl(n+1,0);
    for(long long k=1;k<=n;k++){
      for(long long l=k;l<=n;l+=k){
        if(s[l]=='1'){break;}
        if(fl[l]){continue;}
        res+=k;
        fl[l]=1;
      }
    }
    cout << res << "\n";
  }
  return 0;
}