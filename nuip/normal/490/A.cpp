#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  vector<int> v[4];
  int n,a;
  cin>>n;
  rep(i,n){
    cin>>a;
    v[a].pb(i+1);
  }
  int re=min(v[1].size(),min(v[2].size(),v[3].size()));
  cout<<re<<endl;
  rep(i,re){
    rep(j,3)
      cout<<v[j+1][i]<<" ";
    cout<<endl;
  }
  return 0;
}