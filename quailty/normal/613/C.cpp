#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[35];
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    if(n==1)
    {
        printf("%d\n",a[0]);
        for(int i=0; i<a[0]; i++)
            printf("a");
        printf("\n");
    }
    else
    {
        int cnt=0,loc=0;
        for(int i=0; i<n; i++)
            if(a[i]&1)
            {
                cnt++;
                loc=i;
            }
        if(cnt>=2)
        {
            printf("0\n");
            for(int i=0; i<n; i++)
                for(int j=0; j<a[i]; j++)
                    printf("%c",'a'+i);
            printf("\n");
        }
        else
        {
            int g=a[0];
            for(int i=1; i<n; i++)
                g=gcd(g,a[i]);
            printf("%d\n",g);
            if(g%2==0)g/=2;
            for(int k=0; k<g; k++)
            {
                for(int i=0; i<n; i++)
                {
                    if(i==loc)continue;
                    for(int j=0; j<a[i]/(2*g); j++)
                        printf("%c",'a'+i);
                }
                for(int j=0; j<a[loc]/g; j++)
                    printf("%c",'a'+loc);
                for(int i=n-1; i>=0; i--)
                {
                    if(i==loc)continue;
                    for(int j=0; j<a[i]/(2*g); j++)
                        printf("%c",'a'+i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}