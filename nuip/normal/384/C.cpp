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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int main(){
  ll n,a[212345],i,j,re=0;
  scanf("%I64d",&n);
  for(i=0;i<n;i++){
    scanf("%I64d",a+i);
  }

  ll sum=0;
  for(i=0;i<n;i++){
    if(a[i]){
      sum++;
    }else{
      re+=sum;
    }
  }
  cout<<re<<endl;
  return 0;
}