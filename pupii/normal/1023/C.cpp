#include<bits/stdc++.h>
int n,m;
char a[200001];
int nxt[200001];
int stk[200001],tp;
int main(){
    int n,k,N;
    scanf("%d%d",&n,&k);N=n;
    scanf("%s",a+1);
    for(int i=1;i<=n;++i){
        if(a[i]=='(')stk[++tp]=i;
        else{
            if(N!=k)N-=2,a[i]=a[stk[tp]]='g';
            nxt[i]=stk[tp],--tp;
        }
    }
    for(int i=1;i<=n;++i)if(a[i]!='g')putchar(a[i]);
	return 0;
}