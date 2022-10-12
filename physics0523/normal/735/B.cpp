#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,a,b;
  cin >> n >> a >> b;
  if(a>b){swap(a,b);}
  double res=0.0;
  vector<int> v(n);
  for(auto &nx : v){cin >> nx;}
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(int i=0;i<a;i++){
    res+=((double)v[i])/((double)a);
  }
  for(int i=a;i<a+b;i++){
    res+=((double)v[i])/((double)b);
  }
  printf("%.12lf\n",res);
  return 0;
}