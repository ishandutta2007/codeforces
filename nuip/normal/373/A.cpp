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

char str[5];
int cnt[10];

int main(){
  int i,j,k;
  scanf("%d",&k);
  for(i=0;i<4;i++){
    scanf("%s",str);
    for(j=0;j<4;j++){
      if(str[j]=='.')continue;
      cnt[str[j]-'0']++;
    }
  }
  bool f=0;
  for(i=0;i<10;i++){
    if(cnt[i]>2*k){
      f=1;
    }
  }
  cout<<(f?"NO":"YES")<<endl;
  return 0;
}