#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,d;
  cin >> n >> d;
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    vector<int> a={x+d,x-d,d-x,2*n-d-x};
    sort(a.begin(),a.end());
    if(a[1]<=y&&y<=a[2]){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}