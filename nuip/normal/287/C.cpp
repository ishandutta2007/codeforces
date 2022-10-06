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
#include<iomanip>
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
  int i,j,k;
  int n;
  cin>>n;
  if(n/2%2){
    cout<<-1<<endl;
  }else{
    vector<int> re(n,n/2);
    rep(i,n/4){
      re[i*2]=i*2+1;
      re[i*2+1]=n-i*2-1;
      re[n-i*2-1]=n-i*2-2;
      re[n-i*2-2]=i*2;
    }
    rep(i,n)
      cout<<re[i]+1<<" ";cout<<endl;
  } 
  return 0;
}