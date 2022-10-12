#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n),b(2*n+10);
    for(int i=0;i<n;i++){
      cin >> a[i];
      b[a[i]]++;
    }
    int res=0;
    for(int i=2*n+1;i>=1;i--){
      if(b[i]!=0){continue;}
      if(b[i-1]>=1){
        b[i-1]--;
        b[i]++;
      }
    }
    for(int i=1;i<=2*n+1;i++){
      if(b[i]>=1){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}