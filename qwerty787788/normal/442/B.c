#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return ( *(double *)b - *(double *)a );
} 

main()
{
    int an,max,n,i,j,k;
    float b[100];
    double o,ans,q,s,p,a[100],tmp;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    
//  qsort(a,n,sizeof(double),cmp);
//  for(i=0;i<n;i++)
//      a[i]=b[i];

    for(i=1;i<n;i++)
    {
        tmp=a[i];
        for(j=i-1;j>=0 && a[j]<tmp;j--)
            a[j+1]=a[j];
        a[j+1] = tmp;
    }
//    for(i=0;i<n;i++)
  //      printf("%.12f  ",a[i]);
 //   printf("\n");
    
    s=0;
    for(i=0;i<n;i++)
    {
        s+=a[i]/(1-a[i]);
        if(s>=1)
            break;
    }
//  printf("s=%.12f\n",s);
    if(i==n)
        i--;
    max = i;
    o = 0;
//  an = 0;
    for(i=0;i<=max;i++){
        ans=0;
    if(i==0)
        ans = a[i];
    else
    {
        for(j=0;j<=i;j++)
        {
            q=1;
            for(k=0;k<=i;k++)
            {
                if(k!=j)
                    q*=(1-a[k]);
                else
                    q*=a[k];
            }
            ans+=q;
//          printf("%lf %lf\n",q,ans);
        }
    }
    if(ans>o)
        o = ans;
    }
    printf("%.12f\n",o);
    return 0;
}