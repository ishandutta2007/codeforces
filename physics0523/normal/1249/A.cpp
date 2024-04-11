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
    vector<int> a(n);
    for(int i=0;i<n;i++){cin >> a[i];}
    sort(a.begin(),a.end());
    int res=1;
    for(int i=1;i<n;i++){
      if(a[i-1]+1==a[i]){res=2;}
    }
    cout << res << '\n';
  }
}