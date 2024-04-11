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
    vector<long long> a(n),b(m);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    long long g=b[0];
    for(int i=0;i<m;i++){g=gcd(g,b[i]);}
    vector<priority_queue<long long,vector<long long>,greater<long long>>> vp(g);
    long long res,cur=0;
    for(int i=0;i<n;i++){
      vp[i%g].push(a[i]);
      cur+=a[i];
    }
    res=cur;

    int tim=(n/g)+3;
    for(int i=0;i<tim;i++){
      for(int j=0;j<g;j++){
        long long od=vp[j].top();
        vp[j].pop();
        cur-=(2*od);
        vp[j].push(-od);
      }
      res=max(res,cur);
    }
    cout << res << '\n';
  }
  return 0;
}