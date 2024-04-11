#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

int main(){
  int n;
  ld r;
  cin >> n >> r;
  ld pos[n];
  ld xc[n];
  ld mi;
  int ix;
  ld q = (r*2)*(r*2);
  ld v;
  for(int i = 0;i<n;i++){
    cin >> xc[i];
    mi=r;
    for(int j = i-1;j>=0;j--){
      if(abs(xc[i]-xc[j])<=r*2){
        v=(xc[i]-xc[j])*(xc[i]-xc[j]);
        v=q-v;
        v=sqrt(v);
        v+=pos[j];
        mi=max(mi,v);
      }
    }
    pos[i]=mi;
    cout << fixed << setprecision(10)<< pos[i] << " ";
  }
  return 0;
}