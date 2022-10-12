#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  sort(a.begin(),a.end());
  double res;
  res=(double)(max(a[0],k-a[n-1]));
  for(int i=1;i<n;i++){
    double d=a[i];
    d-=a[i-1];
    res=max(res,d/2.0);
  }
  printf("%.12lf\n",res);
  return 0;
}