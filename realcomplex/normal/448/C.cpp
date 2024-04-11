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

int color(vector<int> segm){
  if(segm.size() == 0)
    return 0;
  if(segm.size() == 1)
    return 1;
  int v1 = segm.size();
  int v2 = 0;
  int rem = (int)1e9 + 9;
  for(int j : segm)
    rem = min(rem, j);
  for(int &j : segm)
    j -= rem;
  v2 = rem;
  vector<int>T;
  for(int j : segm){
    if(j != 0)
      T.push_back(j);
    else{
      v2 += color(T);
      T.clear();
    }
  }
  v2 += color(T);
  
  return min(v1, v2);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  vector<int> aa;
  for(int i = 0;i < n; i++ ){
    cin >> a;
    aa.push_back(a);
  }
  cout << color(aa) << "\n";
  return 0;
}