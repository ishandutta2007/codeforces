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
  vector<ll> v(3);
  ll re=0;
  rep(i,3)
    cin>>v[i];
  sort(all(v));
  ll l=v[1]-v[0],r=v[2]-v[1],sum=v[0]+v[1]+v[2];
  if(l<r && (r-l)/3>v[0]){
    cout<<(sum-3*((r-l)/3-v[0]))/3<<endl;
  }else{
    cout<<sum/3<<endl;
  }
  return 0;
  if(r<=l){
    re+=r+v[0];
    r=v[1]-r-v[0];
    re+=r/3+(r%3==2);
  }else{
    re+=l;
    l=r-l;
    if(l/3>=v[0])
      re+=v[0]*2;
    else{
      re+=l/3*2;
      re+=v[0]-l/3;
    }
  }
  cout<<re<<endl; 
  return 0;
}