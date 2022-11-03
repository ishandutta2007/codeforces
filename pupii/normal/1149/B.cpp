// NIUBI GSY
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
char s[4][260],world[100010];
int f[251][251][251];
int n,q,nxt[27][100010],lst[27];
il vd dp(int x,int y,int z){
	if(!x&&!y&&!z){f[x][y][z]=0;return;}
	f[x][y][z]=1e8;
	if(x&&f[x-1][y][z]<1e8)f[x][y][z]=std::min(f[x][y][z],nxt[s[1][x]-'a'][f[x-1][y][z]]);
	if(y&&f[x][y-1][z]<1e8)f[x][y][z]=std::min(f[x][y][z],nxt[s[2][y]-'a'][f[x][y-1][z]]);
	if(z&&f[x][y][z-1]<1e8)f[x][y][z]=std::min(f[x][y][z],nxt[s[3][z]-'a'][f[x][y][z-1]]);
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	n=gi(),q=gi();
	scanf("%s",world+1);
	for(int j=0;j<26;++j)lst[j]=1e8;
	for(int i=n;~i;--i){
		for(int j=0;j<26;++j)nxt[j][i]=lst[j];
		if(i)lst[world[i]-'a']=i;
	}
	char ch[2],c;int i,len[4]={0};
	while(q--){
		scanf("%s",ch);
		if(ch[0]=='+'){
			i=gi();c=getchar();s[i][++len[i]]=c;
			if(i==1){
				for(int i=0;i<=len[2];++i)
					for(int j=0;j<=len[3];++j)
						dp(len[1],i,j);
			}else if(i==2){
				for(int i=0;i<=len[1];++i)
					for(int j=0;j<=len[3];++j)
						dp(i,len[2],j);
			}else{
				for(int i=0;i<=len[1];++i)
					for(int j=0;j<=len[2];++j)
						dp(i,j,len[3]);
			}
		}else i=gi(),--len[i];
		//		for(int i=0;i<=len[1];++i)
		//			for(int j=0;j<=len[2];++j)
		//			for(int k=0;k<=len[3];++k)
		//				printf("%d %d %d %d\n",i,j,k,f[i][j][k]);
		puts(f[len[1]][len[2]][len[3]]<=n?"YES":"NO");
	}
	return 0;
}