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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    if(n==1){cout << "0\n";continue;}

    int res=a[n-1]-a[0];
    int mx=a[1];
    for(int i=1;i<n;i++){
      mx=max(a[i],mx);
    }
    res=max(res,mx-a[0]);
    int mi=a[0];
    for(int i=0;i<n-1;i++){
      mi=min(a[i],mi);
    }
    res=max(res,a[n-1]-mi);
    for(int i=0;i<n;i++){
      res=max(res,a[i]-a[(i+1)%n]);
    }
    cout << res << "\n";
  }
  return 0;
}