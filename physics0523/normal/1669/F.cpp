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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=0;
    int ap=1,bp=n-2;
    long long aw=a[0],bw=a[n-1];
    while(ap<=bp+1){
      if(aw==bw){
        res=max(res,ap+(n-1-bp));
        aw+=a[ap];ap++;
        bw+=a[bp];bp--;
      }
      else if(aw<bw){aw+=a[ap];ap++;}
      else{bw+=a[bp];bp--;}
    }
    cout << res << '\n';
  }
  return 0;
}