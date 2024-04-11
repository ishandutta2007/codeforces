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
  int i,j;
  int k,d;
  cin>>k>>d;
  if(k==1){
    cout<<d<<endl;
    return 0;
  }else if(d==0){
    cout<<"No solution"<<endl;
    return 0;
  }
  putchar('1');
  for(i=1;i<k-1;i++){
    putchar('0');
  }
  putchar('0'+d-1);
  cout<<endl;
  return 0;
}