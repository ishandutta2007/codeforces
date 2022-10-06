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
  int i,j,k;
  int n;
  cin>>n;
  vector<string> f(n),s(n);
  rep(i,n){
    cin>>f[i]>>s[i];
    if(f[i]>s[i])
      swap(f[i],s[i]);
  }
  int p,perm[n];
  rep(i,n){
    cin>>p;
    perm[i]=p-1;
  }
  string cur="";
  rep(i,n){
    if(cur<f[perm[i]]){
      cur=f[perm[i]];
    }else if(cur<s[perm[i]]){
      cur=s[perm[i]];
    }else{
      cout<<"NO"<<endl;
      return 0;
    }
   // cout<<cur<<endl;
  }
  cout<<"YES"<<endl;
  return 0;
}