#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

int main() {
 ll kpos[11];
 ll kneg[11];
 for (int i=0;i<=10;i++) {kpos[i]=0;kneg[i]=0;}
 int n; scanf("%d",&n); ll res=0;
 for (int i=1;i<=n;i++)
 {
  int a; scanf("%d",&a);
  if (a>0) {res+=kneg[a];kpos[a]++;} else
   if (a<0) {res+=kpos[-a];kneg[-a]++;} else {res+=kneg[0];kneg[0]++;}
 }
 printf("%I64d",res);
 return 0;
 }