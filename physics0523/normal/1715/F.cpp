#include<bits/stdc++.h>

using namespace std;
using pd=pair<double,double>;

double ask(vector<pd> &p){
  printf("? %d\n",p.size());
  for(auto &nx : p){
    printf("%.15lf %.15lf\n",nx.first,nx.second);
  }
  fflush(stdout);
  double res;
  scanf("%lf",&res);
  return res;
}

void ans(double x,double y){
  printf("! %lf %lf\n",x,y);
  fflush(stdout);
  return;
}

int main(){
  int d1,d2;
  scanf("%d%d",&d1,&d2); //dummy
  vector<pd> p;
  p.push_back({-1,0});
  for(int i=0;i<100;i++){
    double ofs=1.5*((double)i);
    p.push_back({0,ofs});
    p.push_back({100,ofs});
    p.push_back({100,ofs+0.5});
    p.push_back({0,ofs+0.5});
  }
  p.push_back({-1,p.back().second});

  double r0=ask(p);
  for(auto &nx : p){nx.second+=0.5;}
  double r1=ask(p);
  double r2=1.0-r0-r1;

  double ofs2=0.0;
  if(r1>=r0 && r1>=r2){ofs2=0.5;}
  if(r2>=r0 && r2>=r1){ofs2=1.0;}

  vector<pd> p2;
  p2.push_back({-1,ofs2});
  for(int i=0;i<100;i++){
    double ofs=1.5*((double)i);
    double len=0.0001*((double)(i+1));
    p2.push_back({0,ofs+ofs2});
    p2.push_back({100,ofs+ofs2});
    p2.push_back({100,ofs+ofs2+len});
    p2.push_back({0,ofs+ofs2+len});
  }
  p2.push_back({-1,p.back().second});

  double zy=(ask(p2)*10000.0-1.0)*1.5+ofs2;

  vector<pd> p3;
  p3.push_back({-1,ofs2});
  for(int i=0;i<100;i++){
    double ofs=1.5*((double)i);
    double len=0.5;
    p3.push_back({0,ofs+ofs2});
    p3.push_back({100,ofs+ofs2+len});
    p3.push_back({0,ofs+ofs2+len});
  }
  p3.push_back({-1,p.back().second});

  double x=(100.0-ask(p3)*200.0)-0.5;

  vector<pd> p4={{-200,0},{-200,zy},{200,zy},{200,0}};
  zy-=ask(p4);
  ans(x,zy);
  return 0;
}