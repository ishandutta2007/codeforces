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

vector<int> a[100];

ll gcd(ll n,ll m){
  if(n<m)swap(n,m);

  if(m==0)return n;
  return gcd(m,n%m);
}

int main(){
  int n,i,j;
  ll gcdA=0,max=0,tmp;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%I64d",&tmp);
    gcdA=gcd(gcdA,tmp);
    if(max<tmp)max=tmp;
  }
  cout<<(((max/gcdA)-n)%2?"Alice":"Bob")<<endl;
  return 0;
}