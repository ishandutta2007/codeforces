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
  ll i,j,k;
  ll n;
  cin>>n;
  vector<ll> b(n);
  rep(i,n)
    cin>>b[i];
  sort(all(b));
  cout<<b.back()-b[0]<<" ";
  j=k=0;
  rep(i,n){
    j+=(b[i]==b[0]);
    k+=(b[i]==b.back());
  }
  if(b[0]==b.back()){
    cout<<n*(n-1)/2<<endl;
  }else{
    cout<<j*k<<endl;
  }
  return 0;
}