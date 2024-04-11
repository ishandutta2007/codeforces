#include <bits/stdc++.h>
int q,t,j;
long long x,k,cnt,a[64];
int main() {
  scanf("%d",&q);
  while (q--) {
    scanf("%d%lld",&t,&x);
    for (j=0; (1LL<<j)<=x; j++);
    cnt=(1LL<<(j-1));
    if (t==3) {
      while (j>1) {
        printf("%lld ",x);
        x=((x-cnt+a[j])%cnt+cnt)%cnt+cnt;
        x/=2;
        cnt/=2;
        j--;
        if (cnt==0) break;
        x=((x-cnt-a[j])%cnt+cnt)%cnt+cnt;
      }
      puts("1");
    } else {
      scanf("%lld",&k);
      k=(k%cnt+cnt)%cnt;
      a[j]=((a[j]+k)%cnt+cnt)%cnt;
      if (t==2) for (j++; j<64; j++) {
        k*=2;
        cnt*=2;
        a[j]=((a[j]+k)%cnt+cnt)%cnt;
      }
    }
  }
  return 0;
}