#include<bits/stdc++.h>

using namespace std;
using pd=pair<double,double>;

int main(){
  int n;
  double t;
  scanf("%d%lf",&n,&t);
  vector<pd> pv(n);
  for(int i=0;i<n;i++){
    scanf("%lf",&pv[i].second);
  }
  for(int i=0;i<n;i++){
    scanf("%lf",&pv[i].first);
  }
  double res=0.0;
  double ta=0.0,tb=0.0;
  vector<pd> a,b;
  for(int i=0;i<n;i++){
    if(pv[i].first==t){res+=pv[i].second;}
    if(pv[i].first<t){
      a.push_back(pv[i]);
      ta+=(t-pv[i].first)*pv[i].second;
    }
    if(pv[i].first>t){
      b.push_back(pv[i]);
      tb+=(pv[i].first-t)*pv[i].second;
    }
  }

  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  sort(b.begin(),b.end());
  ta=min(ta,tb);
  tb=ta;
  for(auto &nx : a){
    double dt=(t-nx.first);
    double am=min(nx.second,ta/dt);
    res+=am;
    ta-=(am*dt);
  }
  for(auto &nx : b){
    double dt=(nx.first-t);
    double am=min(nx.second,tb/dt);
    res+=am;
    tb-=(am*dt);
  }

  printf("%.12lf\n",res);
  return 0;
}