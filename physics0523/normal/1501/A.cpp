#include<bits/stdc++.h>

using namespace std;

int c2(int x){return (x+1)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int res=0;
    vector<int> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){cin >> a[i] >> b[i];}
    vector<int> tm(n+1,0);
    for(int i=1;i<=n;i++){cin >> tm[i];}
    for(int i=0;i<n;i++){
      res=max(res+c2(b[i]-a[i]),b[i])+(a[i+1]-b[i]+tm[i+1]);
    }
    cout << res << '\n';
  }
  return 0;
}