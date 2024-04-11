// https://physics0523.hatenablog.com/entry/2020/01/14/061813
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main(){
  int n;
  cin >> n;
  a.resize(n);
  for(int i=0;i<n;i++){
    a[i].resize(n);
    for(int j=0;j<n;j++){
      if(i==j){a[i][j]=0;}
      else{a[i][j]=1;}
    }
  }
  int bas=2;
  int sp=n-1;
  int len=(n-2)/2;
  for(int i=0;i<(2*len);i+=2){
    deque<int> deq;
    deq.push_back(i);
    for(int j=1;j<=len;j++){
      if(j%2){
        deq.push_back( (i+j) % (n-1) );
        deq.push_front( ((n-1)+i-j) % (n-1) );
      }
      else{
        deq.push_front( (i+j) % (n-1) );
        deq.push_back( ((n-1)+i-j) % (n-1) );
      }
    }
    deq.push_front(sp);
    deq.push_back(sp);
    int tag=-1,fg=0;
    for(auto &nx : deq){
      if(tag!=-1){
        a[tag][nx]=bas+fg;
        a[nx][tag]=bas+fg;
      }
      tag=nx;
      fg=1-fg;
    }
    bas+=2;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j){cout << ' ';}
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}