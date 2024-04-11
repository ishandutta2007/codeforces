#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int s[51][51],real[101];
int wl[51][51],wr[51][51];// wl[i][j]: weight of node rj for node li ; wr[i][j]: weight of node li for node rj 
int matchl[51],matchr[51];// matchl[lnode]=rnode
int sortedl[51][51],triedl[51],matchcnt;
il vd trymatch(int lnode,int rnode){if(!matchr[rnode]||wr[matchr[rnode]][rnode]<wr[lnode][rnode])matchcnt+=!matchr[rnode],matchl[matchr[rnode]]=0,matchl[lnode]=rnode,matchr[rnode]=lnode;}
int main(){
	int orzyyb=gi();
	while(orzyyb--){
		int n=gi();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				s[i][j]=gi();
		puts("B");fflush(stdout);
		char op[2];scanf("%s",op);int st=gi();
		if(op[0]=='D')for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)s[i][j]=-s[i][j];
		if(st<=n)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)wl[i][j]=-s[i][j],wr[i][j]=s[i][j];
		else for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)wl[i][j]=s[i][j],wr[i][j]=-s[i][j];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)sortedl[i][j]=j;
			std::sort(sortedl[i]+1,sortedl[i]+n+1,[&](int a,int b){return wl[i][a]>wl[i][b];});
		}
		memset(matchl,0,sizeof matchl);memset(matchr,0,sizeof matchr);memset(triedl,0,sizeof triedl);
		matchcnt=0;while(matchcnt!=n)
			for(int j=1;j<=n;++j)
				if(!matchl[j])trymatch(j,sortedl[j][++triedl[j]]);
		for(int i=1;i<=n;++i)assert(matchl[i]&&matchr[i]);
		while(1){
			printf("%d\n",st<=n?matchl[st]+n:matchr[st-n]);fflush(stdout);
			st=gi();assert(st!=-2);if(st==-1)break;
		}
	}
	return 0;
}