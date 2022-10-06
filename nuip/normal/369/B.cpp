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

int n,k,l,r,sa,sk;

int minScore(int sum,int n,int mx){
  if(n==0)return 0;
  //if((sum+n-1)/n<=mx){
    for(int i=0;i<n;i++)
      printf("%d ",sum/n+(i<sum%n));
    return sum/n;
  //}return -1;
}

int main(){
  scanf("%d %d %d %d %d %d",
        &n,&k,&l,&r,&sa,&sk);
  int mins,mid=minScore(sk,k,r);
  minScore(sa-sk,n-k,mid);
  return 0;
}