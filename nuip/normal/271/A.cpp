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

bool same(char year[]){
  int len=strlen(year);
  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      if(year[i]==year[j]){
        return 1;
      }
    }
  }
  return 0;
}
int main(){
  int num;
  cin>>num;

  char year[6];
  do{
    num++;
    sprintf(year,"%d",num);
  }while(same(year));
  cout<<year<<endl;
  
  return 0;
}