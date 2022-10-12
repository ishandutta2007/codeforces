#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,2e9);
    vector<int> p(k),q(k);
    for(auto &nx : p){cin >> nx;}
    for(auto &nx : q){cin >> nx;}
    for(int i=0;i<k;i++){a[p[i]]=min(a[p[i]],q[i]);}
    for(int i=1;i<=n;i++){a[i]=min(a[i],a[i-1]+1);}
    for(int i=n-1;i>=0;i--){a[i]=min(a[i],a[i+1]+1);}
    for(int i=1;i<=n;i++){
      if(i-1){cout << ' ';}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}