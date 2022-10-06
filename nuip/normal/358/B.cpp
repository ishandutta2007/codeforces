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

string code,str="<3";
int n;

int main(){
  int i,j;
  char temp[112345];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s",temp);
    str+=string(temp)+"<3";
  }
  scanf("%s",temp);
  code=string(temp);

  if(str.size()>code.size()){
    cout<<"no"<<endl;
    return 0;
  }
  for(i=j=0;i<str.size() && j<code.size();j++){
    i+=(str[i]==code[j]);
  }
  cout<<(i==str.size()?"yes":"no")<<endl;
  return 0;
}