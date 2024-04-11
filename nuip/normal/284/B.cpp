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


int main(){
  ll n,i,a=0,f=0,ii=0;
  char c;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>c;
    switch(c){
    case 'A':
      a++;
      break;
    case 'F':
      f++;
      break;
    case 'I':
      ii++;
      break;
    default:
      break;
    }
  }
  if(ii==0){
    cout<<a<<endl;
  }else if(ii==1){
    cout<<1<<endl;
  }else{
    cout<<0<<endl;
  }
  return 0;
}