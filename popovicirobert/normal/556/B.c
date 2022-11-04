#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
int v[MAXN];
int main(){
    int n,i,flag,con;
    scanf("%d" ,&n);
    for(i=0;i<n;i++)
        scanf("%d" ,&v[i]);
    flag=1;
    con=0;
    while(flag&&con<20000){
        for(i=0;i<n;i++){
           if(i%2==0)
               v[i]=(v[i]+1)%n;
            else{
               v[i]--;
               if(v[i]==-1)
                   v[i]=n-1;
           }
        }
        i=0;
        while(i<n&&v[i]==i)
            i++;
        if(i==n)
             flag=0;
        con++;
    }
    if(flag==0)
        printf("Yes");
    else
        printf("No");
    return 0;
}