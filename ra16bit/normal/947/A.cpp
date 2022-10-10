#include <bits/stdc++.h>
using namespace std;
int x,i,j,r,a[1000100];
int main() {
  scanf("%d",&x);
  for (i=2; i<=x; i++) if (!a[i]) for (j=i; j<=x; j+=i) a[j]=i;
  for (r=i=x-a[x]+1; i<x; i++) if (a[i]!=i) r=min(r,i-a[i]+1);
  printf("%d\n",r);
  return 0;
}