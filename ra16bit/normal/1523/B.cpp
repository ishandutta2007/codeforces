#include <bits/stdc++.h>
using namespace std;
int t,n,i,a[1010];
void makea(int i, int j) {
  printf("%d %d %d\n",1,i+1,j+1);
  //a[i]+=a[j];
}
void makeb(int i, int j) {
  printf("%d %d %d\n",2,i+1,j+1);
  //a[j]-=a[i];
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    printf("%d\n",n*3);
    for (i=0; i<n; i+=2) {
      makea(i,i+1);
      makea(i,i+1);
      makeb(i,i+1);
      makea(i,i+1);
      makea(i,i+1);
      makeb(i,i+1);
    }
  }
  return 0;
}