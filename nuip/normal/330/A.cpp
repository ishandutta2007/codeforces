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


bool ngx[13],ngy[13];

int main(){
  int x,y,i,j,xcnt=0,ycnt=0;
  char c[20];
  memset(ngx,0,sizeof(ngx));
  memset(ngy,0,sizeof(ngy));
  scanf("%d %d",&y,&x);
  for(i=0;i<y;i++){
    scanf("%s",c);
    for(j=0;j<x;j++){
     // cout<<c[j];
      if(c[j]=='S'){
    //    cout<<j<<","<<i<<":"<<ngx[j]<<ngy[i]<<endl;
        if(!ngx[j])xcnt++;
        if(!ngy[i])ycnt++;
        ngx[j]=ngy[i]=1;
      }
    }//cout<<"EOL"<<endl;
  }
//  cout<<xcnt<<","<<ycnt<<endl;
  printf("%d\n",x*y-xcnt*ycnt);
  return 0;
}