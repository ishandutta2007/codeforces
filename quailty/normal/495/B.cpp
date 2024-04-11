#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,tot=0;
    scanf("%d%d",&a,&b);
    if(a==b)printf("infinity\n");
    else{
        if(b==0){
            for(int i=1;i<=(int)sqrt(a);i++){
                if(a%i==0){
                        tot++;
                        if(a/i!=i)tot++;
                }
            }
            printf("%d\n",tot);
        }
        else{
            for(int i=1;i<=(int)sqrt(a-b);i++)
                if((a-b)%i==0){
                        if(i<(double)(a-b)/b)
                        tot++;
                        if((a-b)/i!=i && (a-b)/i<(double)(a-b)/b)
                        tot++;
                }
            printf("%d\n",tot);
        }
    }
    return 0;
}