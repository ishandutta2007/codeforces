#include <cstdio>

char data[200010];

int anspos;
int size;

int max(int a,int b) { return a>b?a:b; }

int main()
{
    int i;
    int tmp;
    anspos=-2e9;
    scanf("%s",data);
    bool exist=false;
    for(size=0;data[size];++size) if(!(data[size]%2)) exist=true;
    if(!exist){
        puts("-1");
        return 0;
    }
    for(i=0;i<size-1;++i){
        if(!(data[i]%2)){
            if(data[i]>data[size-1]){
                tmp=-(size-i-1);
            } else {
                tmp=size-i-1;
            }
            anspos=max(anspos,tmp);
        }
    }
    if(anspos<0) anspos=-anspos;
    anspos=size-anspos-1;
    char t=data[anspos];
    data[anspos]=data[size-1];
    data[size-1]=t;
    puts(data);
    return 0;
}