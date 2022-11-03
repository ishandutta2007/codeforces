#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
    rg int x=0,f=0;rg char ch=getchar();
    while(!isdigit(ch))f^=ch=='-',ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int main(){
	ll w1=gi(),h1=gi(),w2=gi(),h2=gi();
	printf("%lld\n",0ll+h1*2+w1+h2*2+w2+4+abs(w1-w2));
    return 0;
}