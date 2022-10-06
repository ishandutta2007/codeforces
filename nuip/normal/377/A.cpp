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
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

typedef pair<int,int> P;

int n,m,k,ox,oy;
int dist[512][512];
char maps[512][512];
multimap<int,P > dists;
multimap<int,P >::reverse_iterator it,ite;
queue<P> que;

int main(){
  memset(dist,-1,sizeof(dist));
  cin>>n>>m>>k;
  int i,j;
  int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
  for(i=0;i<n;i++)
    scanf("%s",maps[i]);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(maps[i][j]=='.'){
        ox=j,oy=i;
        i=n,j=m;
      }
  dist[oy][ox]=0;
  que.push(P(ox,oy));
  while(!que.empty()){
    P tmp=que.front();
    dists.insert(make_pair(dist[tmp.Y][tmp.X],tmp));
    for(i=0;i<4;i++){
      tmp.X=que.front().X+dx[i];
      tmp.Y=que.front().Y+dy[i];
      if(tmp.X<0 || m<=tmp.X || tmp.Y<0 || n<=tmp.Y
         || dist[tmp.Y][tmp.X]!=-1 || maps[tmp.Y][tmp.X]=='#')
        continue;
      dist[tmp.Y][tmp.X]=dist[que.front().Y][que.front().X]+1;
      que.push(P(tmp.X,tmp.Y));
    }
    que.pop();
  }/*
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      printf("%3d",dist[i][j]);
    }cout<<endl;
  }cout<<"[["<<k<<"]]"<<endl;*/
  for(it=dists.rbegin(),i=0;it!=dists.rend()&&i<k;it++,i++){
//    printf("(%d,%d)",it->Y.X,it->Y.Y);
    maps[it->Y.Y][it->Y.X]='X';
  }
  for(i=0;i<n;i++)
    printf("%s\n",maps[i]);
  return 0;
}