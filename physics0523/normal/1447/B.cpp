#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> a(n*m);
    int neg=0;
    for(auto &nx : a){
      cin >> nx;
      if(nx<0){
        neg++;
        nx*=-1;
      }
    }
    sort(a.begin(),a.end());
    if(neg%2){a[0]*=-1;}
    int res=0;
    for(auto &nx : a){res+=nx;}
    cout << res << '\n';
  }
  return 0;
}