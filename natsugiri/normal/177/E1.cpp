#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;


int n;
int a[100], b[100], c;


int main(){
  
  cin>>n>>c;
  for(int i=0; i<n; i++)
    cin>>a[i]>>b[i];

  
  int ans=0;

  for(int i=0; i<n; i++)
    ans+=a[i];
  
  if(ans==0){
    if(n==c)puts("-1");
    else puts("0");
    return 0;
  }
  
  ans=0;
  
  for(int x=1; ; x++){
    int d=0;
    for(int i=0; i<n; i++)
      d+=a[i]*x/b[i]+1;
      
    if(d==c)ans++;
    if(d>c)break;
  }

  printf("%d\n", ans);
  
  return 0;
}