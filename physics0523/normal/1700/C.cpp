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
    long long res=0;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    vector<long long> rig(n,0);
    vector<long long> lef(n,0);
    for(int i=1;i<n;i++){
      if(a[i-1]<a[i]){
        rig[i]+=(a[i]-a[i-1]);
        res+=rig[i];
      }
      else if(a[i-1]>a[i]){
        lef[i-1]+=(a[i-1]-a[i]);
        res+=lef[i-1];
      }
    }
    for(int i=1;i<n;i++){rig[i]+=rig[i-1];}
    for(int i=n-2;i>=0;i--){lef[i]+=lef[i+1];}
    a[0]-=rig[0];
    a[0]-=lef[0];
    res+=abs(a[0]);
    cout << res << '\n';
  }
  return 0;
}