#include <stdio.h>
int fix[1000020],n,l,k,i;

main()
 {scanf("%d",&n);
  printf("%d\n",n);
  for (i=0;i<n;i++)
   {scanf("%d",&l); fix[l]=1;
    if (fix[1000001-l]) k++;}
  for (i=1;i<=1000000;i++)
   {if (k > 0 && !fix[i] && !fix[1000001-i])
      k--, printf("%d %d ",i,1000001-i);
    if (fix[i] && !fix[1000001-i]) printf("%d ",1000001-i);}
 }