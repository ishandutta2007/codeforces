#include<bits/stdc++.h>
#define pi 3.1415926535897932384

using namespace std;
using pd=pair<double,double>;

double eps=1.5e-6;

double dist(pd a,pd b){
  double res=0.0;
  res+=(a.first-b.first)*(a.first-b.first);
  res+=(a.second-b.second)*(a.second-b.second);
  return sqrt(res);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pd> pt(3);
  for(auto &nx : pt){cin >> nx.first >> nx.second;}
  vector<double> dv={dist(pt[0],pt[1]),dist(pt[1],pt[2]),dist(pt[2],pt[0])};
  sort(dv.begin(),dv.end());

  double res=8.0e18;
  for(int n=3;n<=105;n++){
    double srad=(2.0*pi)/((double)n);
    for(int i=1;i<n;i++){
      for(int j=i+1;j<n;j++){
        vector<pd> vp;
        vp.push_back({1.0,0.0});
        double ai=i;ai/=n;ai*=2.0;ai*=pi;
        vp.push_back({cos(ai),sin(ai)});
        double aj=j;aj/=n;aj*=2.0;aj*=pi;
        vp.push_back({cos(aj),sin(aj)});
        vector<double> cdv={dist(vp[0],vp[1]),dist(vp[1],vp[2]),dist(vp[2],vp[0])};
        sort(cdv.begin(),cdv.end());
        vector<double> ce;
        for(int k=0;k<3;k++){ce.push_back(dv[k]/cdv[k]);}
        sort(ce.begin(),ce.end());
        if(ce[0]<(1.0-eps)*ce[1]){continue;}
        if((1.0+eps)*ce[1]<ce[2]){continue;}
        res=min(res,(((double)n)/2.0)*ce[1]*ce[1]*sin(srad));
      }
    }
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(12) << res << '\n';
  return 0;
}