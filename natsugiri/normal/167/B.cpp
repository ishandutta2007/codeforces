#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n,l,k;
int p[202],a[202];
int id[202];
double d[202][202][222];

bool cmp(int x,int y){
  return a[x]>a[y];
}

double rec(int cnt,int win,int bag){
  int c=id[cnt];
  if(bag>220)bag=220;
  if(d[cnt][win][bag]>-1.0)return d[cnt][win][bag];
  if(cnt==n){
    if(win>=l)return d[cnt][win][bag]=1.0;
    else return d[cnt][win][bag]=0.0;
  }
  if(n-cnt+win<l)return 0.0;
  if(a[c]==-1 && bag==0 && win<l)return 0;

  double r=0;
  if(a[c]>0){
    r+=p[c]/100.0*rec(cnt+1,win+1,bag+a[c]);
    r+=(100.0-p[c])/100.0*rec(cnt+1,win,bag);
  }else{
    if(bag>0)r+=p[c]/100.0*rec(cnt+1,win+1,bag-1);
    r+=(100.0-p[c])/100.0*rec(cnt+1,win,bag);
  }
  return d[cnt][win][bag]=r;
}

int main(){
  scanf("%d%d%d",&n,&l,&k);
  for(int i=0;i<n;i++)scanf("%d",p+i);
  for(int i=0;i<n;i++)scanf("%d",a+i);

  for(int i=0;i<n;i++)id[i]=i;

  sort(id,id+n,cmp);

  for(int i=0;i<202;i++)
    for(int j=0;j<202;j++)
      for(int x=0;x<222;x++)
	d[i][j][x]=-100.0;

  
  printf("%.20f\n",rec(0,0,k));

  return 0;
}