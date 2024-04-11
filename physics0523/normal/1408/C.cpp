#include<bits/stdc++.h>

using namespace std;

int main(void){
  int t;
  int n;
  double l,a[131072];
  int stp,fip;
  double stcl,ficl;
  double stv,fiv;
  cin >> t;
  while(t>0){
    t--;
    cin >> n >> l;
    stp=1;fip=n;
    stcl=0.0;ficl=0.0;
    stv=1.0;fiv=1.0;
    
    a[0]=0.0;a[n+1]=l;
    for(int i=1;i<=n;i++){cin >> a[i];}
    while(stp<=fip){
      if(stcl+(a[stp]-a[stp-1])/stv < ficl+(a[fip+1]-a[fip])/fiv){
        stcl+=((a[stp]-a[stp-1])/stv);
        stp++;
        stv+=1.0;
      }
      else{
        ficl+=((a[fip+1]-a[fip])/fiv);
        fip--;
        fiv+=1.0;
      }
    }
    double ccl=max(stcl,ficl),chd=0.0;
    chd+=((ccl-ficl)*fiv);
    chd+=((ccl-stcl)*stv);
    printf("%.12lf\n",ccl+(a[stp]-a[fip]-chd)/(stv+fiv));
  }
  return 0;
}