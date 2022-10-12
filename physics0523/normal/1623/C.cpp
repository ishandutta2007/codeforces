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
    long long st=0,fi=1000000007,te;
    while(st<=fi){
      vector<long long> b=a;
      te=(st+fi)/2;
      for(int i=n-1;i>=2;i--){
        long long go=max(0ll,b[i]-te);
        go=min(go,a[i]);
        go/=3;

        b[i]-=3*go;
        b[i-1]+=go;
        b[i-2]+=2*go;
      }
      bool fl=true;
      for(int i=0;i<n;i++){
        if(b[i]<te){fl=false;}
      }
      if(fl){st=te+1;}else{fi=te-1;}
    }
    cout << fi << '\n';
  }
  return 0;
}