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
#include<cstdio>
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
  int n,m,a,b;
  double c;
  double re=0;
  int x[700];
  cin>>n>>m;
  rep(i,n)
    cin>>x[i+1];
  rep(i,m){
    cin>>a>>b>>c;
    re=max(re,(x[a]+x[b])/c);
  }
//  cout<<re<<endl;
  printf("%.10f\n",re);
  return 0;
}