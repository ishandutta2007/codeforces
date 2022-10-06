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

ll n,coins;

int main(){
  coins=3;
  ll maxc=1,temp,nn,c;
  cin>>n;
  while(coins<n){
    if(coins%n){
      nn=n;
      c=coins;
      temp=0;
      while(nn){
        if(nn%c==0){
          temp++;
          break;
        }
        temp+=nn/c;
        nn%=c;
        c/=3;
      }
      if(temp>maxc)maxc=temp;
    }
    coins*=3;
  }
  cout<<maxc<<endl;
  return 0;
}