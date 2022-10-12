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
    cin >> n;
    vector<string> a(n);
    int sig=0;
    for(auto &nx : a){
      cin >> nx;
      for(auto &ny : nx){sig+=(ny-'0');}
    }
    int res=1e9;
    vector<int> bk(n,0);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int tg=i-j;
        while(tg<0){tg+=n;}
        tg%=n;
        bk[tg]+=(a[i][j]-'0');
      }
    }
    for(int i=0;i<n;i++){
      res=min(res,(sig-bk[i])+(n-bk[i]));
    }
    cout << res << '\n';
  }
  return 0;
}