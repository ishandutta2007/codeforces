#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n;
  cin >> n;
  string a, b;
  pii v1[n];
  string nm[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a >> b;
    nm[i] = a;
    if(b == "rat")
      v1[i].fi = 1;
    else if(b == "child" or b == "woman")
      v1[i].fi = 2;
    else if(b == "man")
      v1[i].fi = 3;
    else
      v1[i].fi = 4;
      
    v1[i].se = i;
  }
  sort(v1, v1 + n);
  for(int i = 0;i < n;i ++ )
    cout << nm[v1[i].se] << "\n";
  return 0;
}