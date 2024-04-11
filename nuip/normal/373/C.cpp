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
  int n,i,j;
  scanf("%d",&n);
  vector<int> s(n);
  for(i=0;i<n;i++)
    scanf("%d",&s[i]);
  sort(s.begin(),s.end());
  int re=0;
  for(j=0,i=n/2;i<n;i++){
   // printf("s[%d]=%d , s[%d]=%d\n",j,s[j],i,s[i]);
    if(s[j]*2<=s[i]){
      re++;
      j++;
      //cout<<"[ok]"<<endl;
      if(j>=n/2)break;
    }
  }
  cout<<n-re<<endl;
  return 0;
}