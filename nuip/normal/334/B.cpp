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

set<pair<int,int> > points;
set<int> x,y;

int main(){
  bool ok=0;
  int i;
  pair<int,int> temp;
  for(i=0;i<8;i++){
    scanf("%d %d",&(temp.X),&(temp.Y));
    points.insert(temp);
    x.insert(temp.X);
    y.insert(temp.Y);
  }
  if(x.size()==3 && y.size()==3 && points.size()==8){
    if(points.count(make_pair(*(++x.begin()),*(++y.begin())))==0){
      ok=1;
    }
  }
  cout<<(ok?"respectable":"ugly")<<endl;
  return 0;
}