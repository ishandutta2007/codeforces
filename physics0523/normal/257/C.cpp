#include<bits/stdc++.h>
#define pi 3.1415926535897932384

using namespace std;
using pai=pair<int,int>;

int main(){
  int n;
  scanf("%d",&n);
  vector<pai> inpv(n),pv;
  for(int i=0;i<n;i++){
    scanf("%d%d",&inpv[i].first,&inpv[i].second);
    if(inpv[i]==make_pair(0,0)){continue;}
    pv.push_back(inpv[i]);
  }

  n=pv.size();

  if(n<=1){
    printf("0.0\n");
    return 0;
  }

  sort(pv.begin(), pv.end(), [](const auto &p1, const auto &p2) {
    return atan2l(p1.second, p1.first) < atan2l(p2.second, p2.first);
  });

  double del=atan2(pv[n-1].second,pv[n-1].first)-atan2(pv[0].second,pv[0].first);
  while(del>=pi){del-=pi;}
  if(del<1.0e-9){printf("0.0\n");return 0;}
  
  double res=360.0;
  for(int i=0;i<n;i++){
    int j=(i+1)%n;
    double cres=atan2(pv[j].second,pv[j].first)-atan2(pv[i].second,pv[i].first);
    while(cres<0.0){cres+=(2.0*pi);}
    res=min(res,360.0-(180.0*(cres/pi)));
  }
  printf("%.12lf\n",res);
  return 0;
}