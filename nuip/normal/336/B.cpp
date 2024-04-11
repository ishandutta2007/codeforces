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

ll r,sq2,m,R;

int main(){

  int i,j;
  cin>>m>>R;
  r=2*m*R+2*(m-1)*2*R;
  sq2=2*(m-1)*R;
  for(i=2;i<m;i++){
    r+=2*(m-i)*2*(i-1)*R;
    sq2+=2*(m-i)*2*R;
  }
  //cout<<r<<" "<<sq2<<endl;
  printf("%lf\n",(double(r)+sqrt(2)*double(sq2))/m/m);
  return 0;
}