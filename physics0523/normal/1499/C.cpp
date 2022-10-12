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
    for(int i=0;i<n;i++){cin >> a[i];}
    long long bf=n-1,bs=n-1;
    long long mf=a[0],ms=a[1];
    long long sf=a[0],ss=a[1];
    long long res=(a[0]+a[1])*n;
    for(int i=2;i<n;i++){
      if(i%2==0){
        //first
        bf--;
        mf=min(a[i],mf);
        sf+=a[i];
      }
      else{
        //second
        bs--;
        ms=min(a[i],ms);
        ss+=a[i];
      }
      res=min(sf+ss+bf*mf+bs*ms,res);
    }
    cout << res << '\n';
  }
  return 0;
}