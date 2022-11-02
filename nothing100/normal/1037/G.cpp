#include<bits/stdc++.h>
using namespace std;
char ch[100010];
int l,q,pre[100010][27],nxt[100010][27],sg[100010][27],preg[100010],f[27];
int calc(int x,int y,int z,int kind){
	if (x>y) return 0;
	if (f[z]!=-1) return f[z];
	int gruddy=0;
	for (int i=0;i<26;i++){
		int o=nxt[x][i],p=pre[y][i];
		if (o>y||o<x) continue;
		//printf("%d %d %d %d %d\n",x,y,z,o,p);
		if (kind==0) gruddy|=(1<<(sg[o-1][z]^preg[o]^preg[p]^calc(p+1,y,i,kind)));
		else gruddy|=(1<<(calc(x,o-1,i,kind)^preg[o]^preg[p]^sg[y][i]));
	}
	int res=0;
	while (gruddy&1) gruddy>>=1,res++;
	//printf("res:%d %d %d %d %d\n",x,y,z,kind,res);
	f[z]=res;
	return f[z];
}
void init(){
	for (int i=1;i<=l;i++){
		for (int j=0;j<26;j++) pre[i][j]=(('a'+j)==ch[i]?i:pre[i-1][j]);
	}
	for (int i=l;i;i--)
		for (int j=0;j<26;j++) nxt[i][j]=(('a'+j)==ch[i]?i:nxt[i+1][j]);
	for (int i=1;i<=l;i++){
		int now=ch[i]-'a';
		preg[i]=preg[pre[i-1][now]]^sg[i-1][now];
		for (int j=0;j<26;j++) f[j]=-1;
		for (int j=0;j<26;j++)
			if (pre[i][j]!=0) sg[i][j]=calc(pre[i][j]+1,i,j,0);
	}
}
int main(){
	scanf("%s",ch+1);
	l=strlen(ch+1);
	init();
	scanf("%d",&q);
	while (q--){
		int o,p;
		scanf("%d%d",&o,&p);
		for (int j=0;j<=26;j++) f[j]=-1;
		if (calc(o,p,26,1)) printf("Alice\n");
		else printf("Bob\n");
	}
}