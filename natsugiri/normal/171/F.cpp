#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int M = 1000000;
bool prime[M];

int rev(int x){
  stringstream ss;
  string s;
  ss<<x;
  ss>>s;
  reverse(s.begin(),s.end());
  ss.clear();
  ss<<s;
  ss>>x;
  return x;
}

int main(){
  int n;
  scanf("%d",&n);
  memset(prime,1,sizeof prime);
  for(int i=2;i*i<M;i++)
    for(int j=i*i;j<M;j+=i)
      prime[j]=0;
  int t;
  for(t=13;n;t++){
    if(prime[t]){
      int r=rev(t);
      if(t!=r && prime[r])n--;
    }
  }
  printf("%d\n",t-1);
  return 0;
}