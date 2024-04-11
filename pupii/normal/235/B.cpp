// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int n=gi();
    double x1=0,x2=0,p;
    for(int i=1;i<=n;++i)scanf("%lf",&p),x2=x2+(2*x1+1)*p,x1=(x1+1)*p;
    printf("%.8lf\n",x2);
    return 0;
}