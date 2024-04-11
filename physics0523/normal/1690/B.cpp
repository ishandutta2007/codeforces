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
      d=max(d,a[i]-b[i]);
    }
    for(int i=0;i<n;i++){
      a[i]=max(0ll,a[i]-d);
    }
    cout << ((a==b)?"YES\n":"NO\n");
  }
  return 0;
}