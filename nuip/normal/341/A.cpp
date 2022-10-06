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
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >


using namespace std;
typedef __int64 ll;

vector<long> pos;

ll gcd(ll n,ll m){
  if(n<m)swap(n,m);

  if(m==0)return n;
  return gcd(m,n%m);
}

int main(){
  long temp;
  ll sum=0,n,i,j,sum2=0;
  scanf("%I64d",&n);
  for(i=0;i<n;i++){
    scanf("%ld",&temp);
    pos.pb(temp);
    sum2+=temp;
  }
  
  sort(pos.begin(),pos.end());
  for(i=0;i<n;i++){
    sum+=pos[i]*(-n+1+2*i);
//    cout<<sum<<endl;
  }
  sum*=2;
  sum+=sum2;
  ll gcdd=gcd(sum,n);
//  cout<<gcdd<<endl;
  sum/=gcdd;
  n/=gcdd;

 // printf("%I64d %I64d\n",sum,n);
  cout<<sum<<" "<<n<<endl;
  return 0;
}