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
    vector<long long> a(n),b(n);
    long long d=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      cin >> b[i];
    }
    long long end=0;
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << b[i]-max(end,a[i]);
      end=max(end,b[i]);
    }cout << '\n';
  }
  return 0;
}