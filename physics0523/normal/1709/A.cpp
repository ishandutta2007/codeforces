#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int x;
    cin >> x;
    vector<int> a(4);
    cin >> a[1] >> a[2] >> a[3];
    if(a[x]==0){cout << "NO\n";continue;}
    if(a[a[x]]==0){cout << "NO\n";continue;}
    cout << "YES\n";
  }
  return 0;
}