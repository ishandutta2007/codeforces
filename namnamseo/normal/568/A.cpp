#include <cstdio>

int stack[1001];
bool isPalin(int x)
{
    int top=0;
    while(x) stack[top++]=x%10, x/=10;
    int i,j;
    for(i=0,j=top-1;i<j;++i,--j) if(stack[i]!=stack[j]) return false;
    return true;
}
bool compo[2000001];

int main()
{
    int p,q;
    scanf("%d%d",&p,&q);
    int n;
    int phi=0, rub=0, last=-1;
    int i;
    compo[1]=true;
    int j;
    for(i=2;i<=2000000;++i){
        if(!compo[i]){
            for(j=i*2;j<=2000000;j+=i) compo[j]=true;
        }
    }
    for(n=1;n<=2000000;++n){
        if(isPalin(n)) ++rub;
        if(!compo[n]) ++phi;
        if(phi*q<=p*rub) last=n;
    }
    if(last!=2000000 && last!=-1) printf("%d\n",last);
    else puts("Palindromic tree is better than splay tree");
    return 0;
}