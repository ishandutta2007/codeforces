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

  ll n,m,s;
ll hoge(ll a,ll b){
  ll mx=0,i,j;
  for(i=1;i<=sqrt(a);i++){
    if(a%i)continue;
    if(s-i+2>0){
      ll tmp=(a/i)*int(b/(s-i+2));
      //  cout<<tmp<<endl;
      mx=max(mx,tmp);
    }
    if(s-a/i+2>0){
      ll temp=i*int(b/(s-(a/i)+2));
      //  cout<<temp<<endl;
      mx=max(mx,temp);
    }
  }
  return mx;
}

int main(){
  ll i,j,k;
  cin>>n>>m>>s;
  if(n+m-2<s){
    cout<<-1<<endl;
    return 0;
  }
  ll mx=max(hoge(n,m),hoge(m,n));
 // cout<<mx<<endl;
  cout<<(mx>0?mx:-1)<<endl;
  return 0;
}