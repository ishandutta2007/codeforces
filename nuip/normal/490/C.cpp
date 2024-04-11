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
  string num;
  ll a,b;
  cin>>num>>a>>b;
  ll pa=0,pb=0;
  vector<ll> p(num.size(),1);
  rrep(i,num.size()){
    pb=(pb+(num[i]-'0')*p[i]%b)%b;
    if(i)p[i-1]=p[i]*10%b;
  }
  rep(i,num.size()-1){
    pa=(pa*10%a+num[i]-'0')%a;
    pb=(pb+b-(num[i]-'0')*p[i]%b)%b;
    if(num[i+1]=='0')
      continue;
    if(pa==0 && pb==0){
      cout<<"YES"<<endl;
      cout<<num.substr(0,i+1)<<endl<<num.substr(i+1)<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}