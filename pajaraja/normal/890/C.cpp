#include <bits/stdc++.h> 
int cnt[200007]; 
int main() { 
int x,n,sol=1; 
scanf("%d",&n); 
for(int i=0;i<n;i++) { scanf("%d",&x); cnt[x]++; }
 for(int i=0;i<n;i++) sol+=fmax(0,cnt[i]-1); printf("%d",sol); }