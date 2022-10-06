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

int a,b,re;

int main(){
  cin>>a>>b;
  int sum=a,q;
  while(sum>=b){
    q=sum/b;
    re+=b*q;
    sum+=q-b*q;
   // cout<<sum<<endl;
  }
  cout<<re+sum<<endl;
  return 0;
}