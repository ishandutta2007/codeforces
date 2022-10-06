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

using namespace std;

bool prime[100010];

int nextP(int n){
  int i=0;
  do{
    i++;
  }while(prime[n+i]==0);
  return i;
}

int main(){
  memset(prime,1,sizeof(prime));

  prime[1]=0;
  for(int i=2;i<100010;i++){
    if(prime[i])
      for(int j=i*2;j<100010;j+=i){
        prime[j]=0;
      }
  }

  int x,y;
  scanf("%d %d",&y,&x);

  int verMin,horMin;
  verMin=y*100;
  horMin=x*100;
  int *ver;
  ver=new int[x];
  for(int i=0;i<x;i++){
    ver[i]=0;
  }

  int change;
  vector<vector<short int> > mat;
  for(int i=0;i<y;i++){
    vector<short int> tmp;
    change=0;
    for(int j=0;j<x;j++){
      int temp;
      scanf("%d",&temp);
      tmp.push_back((short)prime[temp]);
      if(prime[temp]==0){
        int hoge=nextP(temp);
        change+=hoge;
        ver[j]+=hoge;
      }
    }
    mat.push_back(tmp);
    horMin=min(horMin,change);
//    printV(tmp);
  }
//  cout<<horMin<<endl;
  verMin=ver[0];
  for(int i=1;i<x;i++){
//    cout<<ver[i]<<",";
    verMin=min(verMin,ver[i]);
  }
  cout<<min(verMin,horMin)<<endl;
  return 0;
}