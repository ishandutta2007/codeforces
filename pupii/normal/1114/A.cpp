

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
	int x=gi(),y=gi(),z=gi(),a=gi(),b=gi(),c=gi();
	if(x<=a)a-=x,b+=a;
	else return puts("NO"),0;
	if(y<=b)b-=y,c+=b;
	else return puts("NO"),0;
	if(z<=c)puts("YES");
	else return puts("NO"),0;
    return 0;
}