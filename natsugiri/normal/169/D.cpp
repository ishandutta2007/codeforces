#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const long double EPS=1e-9;

typedef long long LL;
int n,k,h;
int m[100000],v[100000],id[100000];
int ans[100000];
double x;


bool cmp(int a,int b){return m[a]!=m[b]?m[a]<m[b]:v[a]<v[b];}

int main(){
  
  scanf("%d%d%d",&n,&k,&h);
  for(int i=0;i<n;i++)scanf("%d",m+i);
  for(int i=0;i<n;i++)scanf("%d",v+i);
  for(int i=0;i<n;i++)id[i]=i;
  
  sort(id,id+n,cmp);
  long double l=0,r=1e20,c;
  for(int i=0;i<200;i++){
    c=(l+r)/2;
    int t=0,j;
    for(j=1;j<=k;j++){
      for(;t<n && (double)j*h+EPS>v[id[t]]*c;t++);
      if(t==n)break;
      t++;
    }
    if(j>k)r=c;
    else l=c;
  }
  int t=0;
  for(int j=1;j<=k;j++){
    for(;t<n && (double)j*h+EPS>v[id[t]]*r;t++);
    printf("%d%c",id[t]+1,j==k?'\n':' ');
    t++;
  }

  return 0;
}