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
  string str,re;
  int num;
  cin>>str;
  cin>>num;

  for(int i=0;i<str.size();i++){
    char ch=tolower(str[i]);
    if(ch<num+97){
      re+=toupper(ch);
    }else{
      re+=tolower(ch);
    }
  }
  cout<<re<<endl;
  return 0;
}