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

int bit[1123456],n;

void add(int p,int v){
  int i;
//  cout<<p<<","<<n<<endl;
  for(i=p;i<=n;i+=i&-i)
    bit[i]+=v;
 }

int sum(int p){
  int i,re=0;
  for(i=p;i>0;i-=i&-i)
    re+=bit[i];
  return re;
}

int main(){
  int i,j,k;
  cin>>n;
  vector<int> a(n),b(n),c(n);
  rep(i,n)
    cin>>a[i];
  map<int,int> bc,cc;
  rep(i,n)
    b[i]=++bc[a[i]];
  for(i=n-1;i>=0;i--)
    c[i]=++cc[a[i]];

  ll re=0;
  rep(i,n){
    re+=sum(c[i]);
    add(b[i],1);
  }
  cout<<ll(n)*(n-1)/2-re<<endl;
  return 0;
}