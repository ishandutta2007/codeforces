#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<int> p,q;
  p.push_back(a);
  q.push_back(b);
  for(int i=1;i<=h;i++){
    if(i==a){continue;}
    p.push_back(i);
  }
  for(int i=1;i<=w;i++){
    if(i==b){continue;}
    q.push_back(i);
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << p[i] << ' ' << q[j] << '\n';
    }
    reverse(q.begin(),q.end());
  }
  return 0;
}