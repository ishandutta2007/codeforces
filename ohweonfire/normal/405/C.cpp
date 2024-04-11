#include <stdio.h>
using namespace std;
int main()
{
    int sum=0,n;
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<i;j++)scanf("%d",&x);
            scanf("%d",&x);
            sum+=x;
            for(int j=i+1;j<n;j++)scanf("%d",&x);
    }
    sum=sum & 1;
    int q;
    scanf("%d",&q);
    while(q--)
    {
              scanf("%d",&x);
              if(x==3){printf("%d",sum);continue;}
              scanf("%d",&y);
              sum=!sum;
    }
    
    return 0;
}