#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main(){
	int n=gi(),m=gi(),r=gi(),MX=0,MN=10000;
	while(n--)MN=std::min(MN,gi());
	while(m--)MX=std::max(MX,gi());
	if(MX<MN)printf("%d\n",r);
	else printf("%d\n",r%MN+r/MN*MX);
	return 0;
}