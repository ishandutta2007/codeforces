#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  long long res=1e18;
  for(long long c=1;;c++){
    long long cres=0,cv=1;
    double eval=1;
    for(int i=0;i<n;i++){
      cres+=abs(cv-a[i]);
      if(cres>=3e15){cres=1e18;break;}
      if(i==n-1){break;}
      eval*=c;
      if(eval>=3e15){cres=1e18;break;}
      cv*=c;
    }
    if(cres>1e17){break;}
    res=min(res,cres);
    if(c==1 && n>=60){break;}
  }
  cout << res << '\n';
  return 0;
}