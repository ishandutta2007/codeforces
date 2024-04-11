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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
  int i,j,k;
  string str;
  ll n,v[300],re=0,mx=0;
  cin>>str>>n;
  rep(i,26){
    cin>>v[i+'a'];
    mx=max(mx,v[i+'a']);
  }
  rep(i,str.size())
    re+=v[str[i]]*(i+1);
  rep(i,n)
    re+=mx*(i+1+str.size());
  cout<<re<<endl;
  return 0;
}