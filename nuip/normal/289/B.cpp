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
  long n,m,d,ave,temp,value[10001],remain=0,passed=0;
  ll sum=0,minv,pastSum;
  int i,j,r,past;
  bool flag=0;
  for(i=0;i<10001;i++)
    value[i]=0;
  scanf("%ld %ld %ld",&n,&m,&d);
  //cin>>n>>m>>d;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      scanf("%ld",&temp);
      //cin>>temp;
      value[temp]++;
    }
  }
  
  for(i=0;i<10001;i++){
    if(value[i]==0)
      continue;
    if(flag){
      if(i%d!=r){
        //cout<<-1<<endl;
        printf("-1\n");
        return 0;
      }
      sum=pastSum+(i/d-past/d)*(passed-remain);
    //  cout<<sum<<"("<<passed<<","<<remain<<endl;
      past=i;
      minv=min(minv,sum);
      pastSum=sum;
      passed+=value[i];
      remain-=value[i];
    }else{
      flag=1;
      past=i;
      r=i%d;
      sum=0;
      for(j=0;j<10001;j++){
        if(value[j]==0)continue;
        sum+=(j/d-i/d)*value[j];
        remain+=value[j];
      }
      minv=sum;
      pastSum=sum;
     // cout<<sum<<endl;
      passed+=value[i];
      remain-=value[i];
    }
  }
  printf("%ld\n",minv);
  //cout<<minv<<endl;
  return 0;
}