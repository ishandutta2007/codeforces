#include<cstdio>
#include<vector>
#include<set>
using namespace std;

int n,m,mm,pp;
int pl[100001],mi[100001];
int c[100001];
set<int>se;
int main(){
  int ans,i,x;
  
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++){
    scanf("%d",&x);
    c[i]=x;
    if(x>0){
      pl[x]++;
      pp++;
    }else{
      mi[-x]++;
      mm++;
    }
  }
  for(i=1;i<=n;i++){
    if((int)pl[i]+mm-mi[i]==m){
      se.insert(i);
    }
  }
  for(i=1;i<=n;i++){
    bool tr=0,li=0;
    if(c[i]>0){
      if(se.count(c[i])>0)tr=1;
      if(se.count(c[i])==0||(int)se.size()>1)li=1;
    }else{
      if(se.count(-c[i])>0)li=1;
      if(se.count(-c[i])==0||(int)se.size()>1)tr=1;
    }
    if(tr&&li)puts("Not defined");
    else if(tr)puts("Truth");
    else if(li)puts("Lie");
    else puts("wrong answer");
  }
  return 0;
}