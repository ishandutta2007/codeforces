#include <stdio.h>
#include <algorithm>
#define MN 1000000

int n;
char s[MN+5];

int rm[MN+5],nxt[MN+5];

int gf(int u,int lim){
	if(rm[u]>=lim) return u;
	return nxt[u]==u?u:nxt[u]=gf(nxt[u],lim);
}

int main(){
	scanf("%d%s",&n,&s[1]);
	for(int i=n,v0=n,v1=n;i>=1;i--){
		if(s[i]=='0'){
			v1=-1;
			if(v0==-1) v0=i;
		}
		if(s[i]=='1'){
			v0=-1;
			if(v1==-1) v1=i;
		}
		if(s[i]=='?'){
			if(v0==-1) v0=i;
			if(v1==-1) v1=i;
		}
		rm[i] = std::max(v0,v1)-i+1;
	}
	for(int i=1;i<=n;i++)
		nxt[i] = i+1;
	for(int i=1;i<=n;i++){
		int p=1,ans=0;
		while(1){
			p = gf(p,i);
			if(p==0) break;
			p += i;
			ans++;
		}
		printf("%d ",ans);
	}
}