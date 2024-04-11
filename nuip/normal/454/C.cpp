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
/*
long double poww(long double a,ll b){
  if(b==0)return 1;
  long double tmp=poww(
}*/

int main(){
  int i,j,k;
  double n,m;
  double re=0,tmp;
  cin>>m>>n;
  for(i=1;i<=m;i++){
 //   cout<<i<<","<<n<<","<<pow(i/m,n)<<endl;
    re+=i*(pow(i/m,n)-pow((i-1)/m,n));
  //  cout<<re<<endl;
  }
  printf("%.6lf\n",(double)re);
  return 0;
}