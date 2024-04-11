#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

typedef long long LL;

int n;
LL a[10000], b[10000], c;


int main(){
  
  cin>>n>>c;
  for(int i=0; i<n; i++)
    cin>>a[i]>>b[i];


  bool f=1;
  for(int i=0; i<n; i++)if(a[i])f=0;
  if(f){
    if(n==c)puts("-1");
    else puts("0");
    return 0;
  }
  
  LL r, l;
  l=0; r=1LL<<60;

  f=0;
  for(;r-l>1;){
    LL m=(r+l)/2;
    LL d=0;
    for(int i=0; i<n; i++){
      if((double)a[i]*m/b[i]>(double)c){
	d=c+1;
	break;
      }
      d+=a[i]*m/b[i]+1;
      if(d>c)break;
    }
    
    if(d<c)l=m;
    else r=m;
    
    if(d==c)f=1;
  }
  
  LL k=r;

  l=1; r=1LL<<60;
  
  for(;r-l>1;){
    LL m=(r+l)/2;
    LL d=0;
    for(int i=0; i<n; i++){
      if((double)a[i]*m/b[i]>(double)c){
	d=c+1;
	break;
      }
      d+=a[i]*m/b[i]+1;
      if(d>c)break;
    }
    if(d>c)r=m;
    else l=m;
    
    if(d==c)f=1;
  }

  if(f)cout<<l-k+1<<endl;
  else puts("0");
  
  return 0;
}