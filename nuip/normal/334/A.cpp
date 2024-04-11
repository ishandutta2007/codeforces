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

//==============================================================
//R[h
//`FbN
//==============================================================

int n;
vector<int> nums[104];

int main(){
  cin>>n;
  int i,j,cnt=1;
  for(i=0;i<n/2;i++){
    for(j=0;j<n;j++){
      nums[j].pb(cnt++);
    }
    for(j=n-1;j>=0;j--){
      nums[j].pb(cnt++);
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d%c",nums[i][j],(j==n-1)?'\n':' ');
    }
  }
  return 0;
}