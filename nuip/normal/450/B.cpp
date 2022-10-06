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
//--
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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
  int i,j,k;
  ll x,y,n,dx[]={1,0,-1,-1,0,1,1,0},dy[]={0,1,1,0,-1,-1,0,1},mod=1e9+7;
  cin>>x>>y>>n;
  n=(n+5)%6;//cout<<x*dx[n]+y*dy[n]<<endl;
  cout<<(x*dx[n]+y*dy[n]+3*mod)%mod<<endl;
  return 0;
}