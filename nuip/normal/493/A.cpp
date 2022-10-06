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
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  string str[200],te,c;
  cin>>str['h']>>str['a'];
  int n,t,m;
  cin>>n;
  set<int> a[200],A[200];
  rep(i,n){
    cin>>t>>te>>m>>c;
    if(c=="r"){
      if(!A[te[0]].count(m)){
        cout<<str[te[0]]<<" "<<m<<" "<<t<<endl;
        A[te[0]].insert(m);
      }
    }else{
      if(a[te[0]].count(m) && !A[te[0]].count(m)){
        cout<<str[te[0]]<<" "<<m<<" "<<t<<endl;
        A[te[0]].insert(m);
      }
      a[te[0]].insert(m);
    }
  }
  return 0;
}