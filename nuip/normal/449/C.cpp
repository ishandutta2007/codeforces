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

int pr[112345],used[112345];
vector<int> primes,re;

int main(){
  int i,j,k,n;
  for(i=2;i<112345;i++){
    if(pr[i])continue;
    primes.pb(i);
    for(j=i+i;j<112345;j+=i)
      pr[j]=1;
  }
  cin>>n;
  for(i=1;i<primes.size();i++){
    int p=primes[i];
    if(p*2>n)
      break;
    vector<int> tmp;
    for(j=p;j<=n;j+=p){
      if(used[j])continue;
      used[j]=1;
      tmp.pb(j);
    }
    swap(tmp[0],tmp[1]);
    if(tmp.size()%2)
      used[p*2]=0;
    for(j=tmp.size()%2;j<tmp.size();j++)
      re.pb(tmp[j]);
  }
  for(i=2;i<=n;i+=2){
    if(used[i])continue;
    re.pb(i);
  }
  cout<<re.size()/2<<endl;
  rep(i,re.size()/2)
    cout<<re[2*i]<<" "<<re[2*i+1]<<endl;
  return 0;
}