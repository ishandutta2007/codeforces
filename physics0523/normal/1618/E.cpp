#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

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
    long long sig=0;
    for(auto &nx : a){
      cin >> nx;
      sig+=nx;
    }
    long long ce=llsankaku(n);
    if(sig%ce!=0){cout << "NO\n";continue;}
    sig/=ce;
    vector<long long> res(n);
    bool err=false;
    for(int i=0;i<n;i++){
      int bk=(i+n-1)%n;
      long long bas=(a[i]-a[bk]-sig)*(-1ll);
      if(bas<=0){err=true;break;}
      if(bas%n!=0){err=true;break;}
      res[i]=bas/n;
    }
    if(err){cout << "NO\n";continue;}
    else{
      cout << "YES\n";
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << res[i];
      }cout << '\n';
    }
  }
  return 0;
}