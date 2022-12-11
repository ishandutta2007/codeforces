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

int main(){
  fastIO;
  int n;
  cin >> n;
  int x;
  vector<int> p;
  for(int i = 0; i< n;i ++ ){
    cin >> x;
    if(x == 1)
      p.push_back(i);
  }
  cout << p.size() << "\n";
  p.push_back(n);
  for(int i = 1;i < p.size(); i ++ )
    cout << p[i] - p[i - 1] << " ";
  return 0;
}