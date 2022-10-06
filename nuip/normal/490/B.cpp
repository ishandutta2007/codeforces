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

int e[1123456],nxt[1123456];
int main(){
  std::ios_base::sync_with_stdio(false);
  int i,j,k;
  fill(e,e+1123456,0);
  fill(nxt,nxt+1123456,-1);
  int n,a,b;
  cin>>n;
  rep(i,n){
    cin>>a>>b;
 //   cout<<a<<","<<b<<endl;
    e[a]++;
    e[b]--;
    nxt[a]=b;
  }
  rep(i,1000003){
    if(e[i]==1)
      b=i;
  }
  a=nxt[0];
  rep(i,n/2){
    cout<<b<<" "<<a<<" ";
    a=nxt[a];
    b=nxt[b];
  }
  if(n%2)
    cout<<b;
  cout<<endl;
  return 0;
}