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

using namespace std;

int main(){
  int words,max;
  scanf("%d %d",&words,&max);

  if(words<max*3){
    cout<<"-1"<<endl;
  }else{
    for(int i=0;i<words;i++){
      if(i<max*2){
        cout<<(i%max)+1;
      }else if(i==max*2){
        cout<<max;
      }else if(i<max*3){
        cout<<(i%max);
      }else{
        cout<<1;
      }
      cout<<(i==words-1?"\n":" ");
    }
  }
  return 0;
}