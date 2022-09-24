#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long LL;

const LL M = 1000000;


int n;
string str;


LL f(int l, int r){
  LL ans=0;
  if(r-l>1 && str[l]=='0')return -1;
  for(int i=l; i<r; i++){
    ans=ans*10 + str[i]-'0';
    if(ans>M)return -1;
  }
  return ans;
}


int main(){
  cin>>str;
  n=str.size();
  LL ans=-1;

  for(int i=1; i<n; i++){
    LL x=f(0, i);
    if(x<0)continue;
    
    for(int j=i+1; j<n; j++){
      LL y=f(i, j), z=f(j, n);
      if(y<0 || z<0)continue;

      ans=max(ans, x+y+z);
    }
  }
  
  printf("%d\n", (int)ans);
  return 0;
}