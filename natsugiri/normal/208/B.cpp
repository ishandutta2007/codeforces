#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int n;
string v[128];

set<pair<int, string> >se;

bool pile(string &a, string &b) {
  return a[0]==b[0] || a[1]==b[1];
}
bool game(int m) {
  if (m==1) return 1;
  string x, y;
  if (m>2) {
    y=v[m-3]+v[m-2]+v[m-1];
    if (se.find(make_pair(m,y))!=se.end()) return 0;
  }
  if (pile(v[m-1], v[m-2])) {
    x=v[m-2];
    v[m-2]=v[m-1];
    if (game(m-1)) return 1;
    v[m-2]=x;
  }
  if (m>3 && pile(v[m-1], v[m-4])) {
    x=v[m-4];
    v[m-4]=v[m-1];
    if (game(m-1)) return 1;
    v[m-4]=x;
  }
  if (m>2) se.insert(make_pair(m,y));
  return 0;
}
int main(){
  cin>>n;
  for (int i=0; i<n; i++) cin>>v[i];
  cout<<(game(n)?"YES":"NO")<<endl;
  return 0;
}