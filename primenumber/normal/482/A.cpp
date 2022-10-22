#include <bits/stdc++.h>

#define REP(i,n)  for(int i=0;i<(int)(n);++i)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n,k;
  cin>>n>>k;
  deque<int> s;
  REP(i,k) s.push_back(i+1);
  vector<int> a(n);
  iota(begin(a),end(a),1);
  int f = 0;
  for (int i=k-1;i>=0;--i) {
    if (f%2) {
      a[i] = s.back();
      s.pop_back();
    }else{
      a[i] = s.front();
      s.pop_front();
    }
    ++f;
  }
  REP(i,n) {
    if(i) cout<<' ';
    cout<<a[i];
  }
  cout<<endl;
  return 0;
}