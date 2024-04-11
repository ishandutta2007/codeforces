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
    sort(a.begin(),a.end());
    if(n==2){
      cout << a[0] << ' ' << a[1] << '\n';
      continue;
    }
    int p=1;
    for(int i=2;i<n;i++){
      if((a[i]-a[i-1])<(a[p]-a[p-1])){p=i;}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << a[(p+i)%n];
    }
    cout << "\n";
  }
  return 0;
}