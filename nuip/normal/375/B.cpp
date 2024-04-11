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

int n,m,rowCnt[5123][5123];

int main(){
  scanf("%d %d",&n,&m);
  int i,j,k,mx=0;
  string row;

  int last=-1;
  for(i=0;i<n;i++){
    cin>>row;
    last=-1;
    for(j=0;j<m;j++){
      if(row[j]=='0'){
        if(last!=-1){
          for(k=last;k<j;k++)
            rowCnt[k][j]--;
          last=-1;
        }
      }else{
        if(last==-1)
          last=j;
        rowCnt[j][j]++;
      }
    }
  }
/*  for(i=0;i<m;i++){
    for(j=0;j<m;j++){
      printf("%3d ",rowCnt[i][j]);
    }printf("\n");
  }*/
  for(i=0;i<m;i++){
    for(j=i;j<m;j++){
      rowCnt[i][j+1]+=rowCnt[i][j];
      mx=max(rowCnt[i][j]*(j-i+1),mx);
   //   printf("%3d ",rowCnt[i][j]);
    }//printf("\n");
  }
  cout<<mx<<endl;
  return 0;
}