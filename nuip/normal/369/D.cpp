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
typedef pair<int,int> P;

int n,k,p[3123],sum;
bool hund[3123],zero[3123];
bool sit[3123][3123];
queue<P> que;

int solve(int a,int b,int i){
  que.push(P(a,b));
  que.push(P(-1,0));
  while(1){
    a=que.front().X;
    b=que.front().Y;
    que.pop();
    if(a==-1){
      if(b==k)break;
      que.push(P(a,b+1));
      continue;
    }
    if(sit[a][b])continue;
    if(a>n || b>n+1)continue;
    sit[a][b]=1;
    sum++;
    if(b>=n) continue;
   //  cout<<a<<","<<b<<endl;
    if(!hund[b]){
      if(p[a]!=0 && b+1<=n)
        que.push(P(a,b+1));
    }
    if(!zero[b]){
      if(p[a]!=0)
        que.push(P(b+1,b+2));
      if(p[a]!=100)
        que.push(P(b,b+1));
    }
  }
  return sum;
}
int main(){
  scanf("%d %d",&n,&k);
  int i,j;
  for(i=0;i<n;i++){
    scanf("%d",p+i);
  }
  bool tmp=0,temp=1;
  for(i=n-1;i>=0;i--){
    if(p[i]==100)tmp=1;
    if(p[i]!=0)temp=0;
    hund[i]=tmp;
    zero[i]=temp;
  }
  printf("%d\n",solve(0,1,0));
  return 0;
}