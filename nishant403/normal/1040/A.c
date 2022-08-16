#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,b,n,cost=0;
    scanf("%d %d %d",&n,&a,&b);
    int arr[n];
    for(i=1;i<=n;i++)
    {

        scanf("%d",&arr[i-1]);
    }
    for(i=1;i<=n;i++)
    {
    if(arr[i-1]!= arr[n-i] && arr[n-i]!=2 && arr[i-1]!=2)
    {

        printf("%d",-1);
        exit(0);
    }
    else if(arr[i-1]== arr[n-i] && arr[n-i]!=2 && arr[i-1]!=2)
    {

        continue;
    }
    else if(arr[i-1]==2 && arr[n-i]==2)
    {

        if(a<b)
        {

            cost+=a;
            arr[i-1]=0;
        }
        else
        {

        cost+=b;
        arr[i-1]=1;
    }

    }
    else if( arr[i-1]==2)
    {
        if(arr[n-i]==0)
        {

            cost+=a;
            arr[i-1]=0;
        }
        else
        {

            cost+=b;
            arr[i-1]=1;
        }



    }







    }
    printf("%d",cost);











    return 0;
}