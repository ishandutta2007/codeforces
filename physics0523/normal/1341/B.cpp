#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<int> bk(n,0);
    for(int i=1;i<n-1;i++){
      if(a[i-1]<a[i] && a[i]>a[i+1]){
        // cout << i << ' ';
        bk[i]++;
      }
    }// cout << '\n';
    for(int i=1;i<n;i++){bk[i]+=bk[i-1];}
    int res=-1,rl=0;
    for(int l=0;l<=n-k;l++){
      int st=l+1;
      int fi=l+k-2;
      // cout << st << ' ' << fi << '\n';
      int cur=bk[fi]-bk[st-1];
      if(res<cur){
        res=cur;
        rl=l;
      }
    }
    cout << res+1 << ' ' << rl+1 << '\n';
  }
  return 0;
}