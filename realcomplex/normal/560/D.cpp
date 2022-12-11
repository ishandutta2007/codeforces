#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

string change(string a){
  int n = a.size();
  if(n % 2 == 1)
    return a;
  string s1 = a.substr(0, n/2);
  s1 = change(s1);
  string s2 = a.substr(n/2, n/2);
  s2 = change(s2);
  if(s1 > s2)
    swap(s1, s2);
  return s1 + s2;
}

int main(){
  fastIO;
  string a, b;
  cin >> a >> b;
  a = change(a);
  b = change(b);
  cout << (a == b ? "YES" : "NO");
  return 0;
}