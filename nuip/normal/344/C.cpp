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

ll a,b,sum;

int main(){
  cin>>a>>b;
  do{
    if(a>b){
      sum+=a/b;
      a%=b;
    }else{
      sum+=b/a;
      b%=a;
    }
  }while(a!=b && a*b);
  cout<<sum<<endl;
  return 0;
}