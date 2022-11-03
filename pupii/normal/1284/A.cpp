#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char s[21][21],t[21][21];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=0;i<n;++i)scanf("%s",s[i]);
	for(int i=0;i<m;++i)scanf("%s",t[i]);
	int T=gi(),x;
	while(T--)x=gi()-1,printf("%s%s\n",s[x%n],t[x%m]);
	return 0;
}