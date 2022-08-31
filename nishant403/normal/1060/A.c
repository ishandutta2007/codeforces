#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    char arr[n];
    scanf("%s",arr);
    int i,count=0;
    for(i=1;i<=n;i++)
    {

        if(arr[i-1]=='8')
            count++;
    }
    if(count > n/11)
    {

        count=n/11;
    }

    printf("%d",count);
    return 0;
}