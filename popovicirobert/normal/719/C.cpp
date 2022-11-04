#include <cstdio>
char v1[200001];
char v2[200001];
int main(){
    int i,n,flag,t,x1,x2;
    char a;
    scanf("%d%d" ,&n,&t);
    fgetc(stdin);
    a=fgetc(stdin);
    x1=0;
    while(a>='0'&&a<='9'){
        v1[x1++]=a-'0';
        a=fgetc(stdin);
    }
    flag=0;
    if(a=='.'){
       a=fgetc(stdin);
       flag=1;
    }
    x2=0;
    while(a>='0'&&a<='9'){
        v2[x2++]=a-'0';
        a=fgetc(stdin);
    }
    i=0;
    while(i<x2&&v2[i]<5)
        i++;
    if(i==x2){
        for(i=0;i<x1;i++)
            printf("%d" ,v1[i]);
        if(flag==1)
            printf(".");
        for(i=0;i<x2;i++)
            printf("%d" ,v2[i]);
    }
    else{
        while(i>0){
            if(v2[i]==10){
                v2[i]=0;
                v2[i-1]++;
            }
            else
            if(v2[i]>=5&&t>0){
              v2[i]=-1;
              v2[i-1]++;
              t--;
            }
            i--;
        }
        if((v2[i]>=5&&t>0)||v2[i]==10){
            if(v2[i]<10)
              v2[i]=-1;
            else
              v2[i]=0;
                 v1[x1-1]++;
                 i=x1-1;
                 while(i>=0&&v1[i]==10){
                     v1[i]=0;
                     if(i>0)
                       v1[i-1]++;
                     else
                       printf("1");
                     i--;
                 }
        }
        for(i=0;i<x1;i++)
              printf("%d" ,v1[i]);
        while(x2>0&&(v2[x2-1]==0||v2[x2-1]==-1))
              x2--;
        if(flag==1){
           if(x2>0&&v2[0]!=-1)
            printf(".");
        }
        for(i=0;i<x2&&v2[i]>=0;i++)
            printf("%d" ,v2[i]);
    }
    return 0;
}