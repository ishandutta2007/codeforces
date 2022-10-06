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


stack<char> que;
char tmp;

int main(){
  while(scanf("%c",&tmp)!=EOF){
    if(tmp!='+' && tmp!='-')break;
    if(que.empty()){
      que.push(tmp);
    }else if(que.top()==tmp){
      que.pop();
    }else{
      que.push(tmp);
    }
  }
  cout<<(que.empty()?"Yes":"No")<<endl;
  return 0;
}