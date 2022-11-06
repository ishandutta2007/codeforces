#include <cstdio>

int gtable[110][110];

int gcd(int a,int b){
    int t;
    if(a<b){
        t=a; a=b; b=t;
    }
    if(b==0) return gtable[a][b]=a;
    if(gtable[a][b]){
        return gtable[a][b];
    }
    for(;b;){
        t=a%b;
        a=b; b=t;
    }
    return gtable[a][b]=a;
}

int main()
{
    int ded[2], n;
    int i;
    for(i=0;i<2;i++) scanf("%d",ded+i);
    scanf("%d",&n);
    int to;
    for(i=0;;i=((i+1)&1)){
        to = gcd(ded[i],n);
        if(n<to) break;
        n-=to;
    }
    printf("%d\n",1^i);
    return 0;
}