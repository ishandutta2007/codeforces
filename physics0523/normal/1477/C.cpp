#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

typedef struct{
  long long xz;
  long long yz;
}point;

point vector_plus(point a,point b){
  point r;
  r.xz=a.xz+b.xz;
  r.yz=a.yz+b.yz;
  return r;
}

point vector_minus(point a,point b){
  point r;
  r.xz=a.xz-b.xz;
  r.yz=a.yz-b.yz;
  return r;
}

//naiseki
long long dotproduct(point a,point b){
  return a.xz*b.xz+a.yz*b.yz;
}

//gaiseki
long long crossproduct(point a,point b){
  return a.xz*b.yz-a.yz*b.xz;
}

int main(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<point> pt(n);
  for(int i=0;i<n;i++){cin >> pt[i].xz >> pt[i].yz;}
  
  vector<int> p(n);
  for(int i=0;i<n;i++){p[i]=i;}
  while(1){
    shuffle(p.begin(),p.end(),engine);
    for(int i=2;i<(n-1);i++){
      for(int j=i;j<n;j++){
        swap(p[i],p[j]);
        if(dotproduct(vector_minus(pt[p[i-2]],pt[p[i-1]]),vector_minus(pt[p[i-1]],pt[p[i]]))<0){
          break;
        }
      }
    }
    int fl=1;
    for(int i=2;i<n;i++){
      if(dotproduct(vector_minus(pt[p[i-2]],pt[p[i-1]]),vector_minus(pt[p[i-1]],pt[p[i]]))>=0){
        fl=0;break;
      }
    }
    if(fl==1){break;}
  }
  
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << p[i]+1;
  }
  return 0;
}