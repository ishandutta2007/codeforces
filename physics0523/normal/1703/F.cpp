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
    long long cur=0;
    long long res=0;
    vector<long long> vec(n+5,0);
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){cin >> a[i];}
    for(int i=n;i>=1;i--){
      if(a[i]<i){
        res+=cur;
        vec[a[i]]++;
      }
      cur+=vec[i];
    }
    cout << res << "\n";
  }
  return 0;
}