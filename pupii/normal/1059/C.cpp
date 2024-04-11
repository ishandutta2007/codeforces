#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
main(){
    int n=gi(),N=0;
    if(n==3)puts("1 1 3");
    else if(n==6)puts("1 1 1 2 2 6");
    else{
        int i=0;
        while(n){
            if(n==3)return printf("%d %d %d\n",(1<<i),(1<<i),(1<<i)*3),0;
            int x=n/2+n%2;
            while(x--)printf("%d ",1<<i);
            n/=2;++i;
        }
    }
    return 0;
}