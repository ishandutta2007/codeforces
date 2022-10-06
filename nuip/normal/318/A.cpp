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

ll n,k;

int main(){
  cin>>n>>k;
  if(k<=(n+1)/2){
    cout<<2*k-1<<endl;
  }else{
    k-=(n+1)/2;
    cout<<2*k<<endl;
  }
  return 0;
}