#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> inv(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      inv[a[i]]=i;
    }
    long long res=0;
    long long lef=1e9,rig=-1e9;
    for(long long i=0;i<n;i++){
      lef=min(lef,inv[i]);
      rig=max(rig,inv[i]);
      long long len=rig-lef+1;

      long long r1=lef;
      long long r2=n-1-rig;
      if(r1>r2){swap(r1,r2);}

      long long l0=2*i+1;
      if(l0<=n && len<=l0){
        long long mg=l0-len;
        long long mi,ma;
        mi=max(0ll,mg-r2);
        ma=min(r1,mg);
        res+=max(0ll,ma-mi+1);
      }

      long long l1=2*i+2;
      if(l1<=n && len<=l1){
        long long mg=l1-len;
        long long mi,ma;
        mi=max(0ll,mg-r2);
        ma=min(r1,mg);
        res+=max(0ll,ma-mi+1);
      }
    }
    cout << res << "\n";
  }
  return 0;
}