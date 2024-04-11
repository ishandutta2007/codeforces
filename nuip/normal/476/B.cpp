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
 // std::ios_base::sync_with_stdio(false);
  int i,j,k;
  int p,q;
  string a,b;
  cin>>a>>b;
  p=q=0;
  rep(i,a.size()){
    if(a[i]=='-')
      p--;
    else
      p++;
  }
  rep(i,b.size()){
    if(b[i]=='-')
      p++;
    else if(b[i]=='+')
      p--;
    else
      q++;
  }
  p=abs(p);
  if(p>q || (q-p)%2){
    cout<<0<<endl;
    return 0;
  }
  double re=1;  //mC(m-p)/2
 // cout<<p<<","<<q<<endl;
  rep(i,(q-p)/2){
    re*=1.0*(q-i)/(i+1);
 //   printf("%.10f\n",re);
  }
  rep(i,q)
    re/=2.0;
  printf("%.10f\n",re);
  return 0;
}