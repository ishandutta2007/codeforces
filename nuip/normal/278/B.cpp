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

using namespace std;
typedef __int64 ll;

int main(){
  char abc[]="abcdefghijklmnopqrstuvwxyz";
  bool a[256];
  bool aa[256][256];
  memset(a,0,sizeof(a));
  memset(aa,0,sizeof(aa));
  int n;
  cin>>n;
  char temp[21];
  for(int i=0;i<n;i++){
    cin>>temp;
    int len=strlen(temp);
    for(int j=0;j<len;j++){
      a[temp[j]]=1;
      aa[temp[j]][temp[j+1]]=1;
    }
  }

  bool flag=1;//0
  for(int i=0;i<26;i++){
    if(a[abc[i]]==0){
      flag=0;
      cout<<abc[i]<<endl;
      break;
    }
  }
  if(flag)for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      if(aa[abc[i]][abc[j]]==0){
        cout<<abc[i]<<abc[j]<<endl;
        return 0;
      }
    }
  }
  return 0;
}