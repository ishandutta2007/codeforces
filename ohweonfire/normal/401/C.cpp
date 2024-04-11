#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#define ll  __int64

using namespace std;

const ll mod=1e9+7;

int main( )
{
    int n,m,flag;
    while(~scanf("%d%d",&n,&m))  //n==>0  m==>1
    {
        flag=0;
        if( m > (n+1)*2 ) flag=1;
        if(  n>m+1 ) flag=1;
        if( flag ) printf("-1\n");
        else
        {
            int t;  // 
            if( n == m+1 )
            {
                printf("0");
                n--;
            }
            t=m-n;
            for(int i=1;i<=n*2;i++)
            {
                printf("%d",i%2);
                if(t>0&&i%2==1)
                {
                    printf("1");
                    t--;
                }
            }
            while( t>0 ){
                printf("1");
                t--;
            }
            printf("\n");
        }
    }
    return 0;
}