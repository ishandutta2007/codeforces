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

string str;

int main(){
  ll i,j,heavyCnt=0,sum=0;
  char h[6]="heavy",m[6]="metal";
  cin>>str;
  for(i=0;i<str.size();i++){
    for(j=i;j<str.size();j++){
      if(str.at(j)!=h[j-i])break;
    }
    if(j-i==5){
      heavyCnt++;
    }
    for(j=i;j<str.size();j++){
      if(str.at(j)!=m[j-i])break;
    }
    if(j-i==5){
      sum+=heavyCnt;
    }
  }
  printf("%I64d\n",sum);
  return 0;
}