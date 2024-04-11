#include<bits/stdc++.h>

using namespace std;

#define N 3000000

int n,m;
char s[N];

struct SAM{
	int cnt,p,np,q,nq,mx[N],rgt[N],c[N][30],fa[N],sum[N],qq[N];
	bool fl[N];
	vector<int> ans;
	
	SAM(){np=++cnt;}
	
	void extend(int w){
		p=np; mx[np=++cnt]=mx[p]+1; rgt[np]=1;
		for (;p && !c[p][w];p=fa[p]) c[p][w]=np;
		if (p==0) fa[np]=1;
		else{
			if (mx[q=c[p][w]]==mx[p]+1) fa[np]=q;
			else{
				mx[nq=++cnt]=mx[p]+1;
				memcpy(c[nq],c[q],sizeof c[nq]);
				fa[nq]=fa[q]; fa[q]=fa[np]=nq;
				for (;p && c[p][w]==q;p=fa[p]) c[p][w]=nq;
			}
		}
	}
	
	void calc(){
		for (int i=1;i<=cnt;i++) sum[mx[i]]++;
		for (int i=1;i<=cnt;i++) sum[i]+=sum[i-1];
		for (int i=1;i<=cnt;i++) qq[sum[mx[i]]--]=i;
		for (int i=cnt;i>=1;i--) rgt[fa[qq[i]]]+=rgt[qq[i]];
	}		
			
	int getans(char s[]){
		int len=strlen(s+1),tmp=0,u=1,ret=0;
		for (int i=1;i<=len;i++){
			int w=s[i]-'a';
			for (;u && !c[u][w];u=fa[u]);
			if (!u) u=1,tmp=0;
			else{
				tmp=min(mx[u],tmp)+1;
				u=c[u][w];
			}
			for (;u && mx[fa[u]]>=len/2+1;u=fa[u]) tmp=min(tmp,mx[fa[u]]);
			if (!fl[u] && tmp>=len/2+1) ans.push_back(u),fl[u]=1;
		}
		for (int i=0;i<(int)ans.size();i++) ret+=rgt[ans[i]],fl[ans[i]]=0;
		ans.clear(); return ret;
	}
}sam;
			
		
int main(){
	scanf("%s%d",s+1,&n); m=strlen(s+1);
	for (int i=1;i<=m;i++) sam.extend(s[i]-'a');
	sam.calc();
	for (int i=1;i<=n;i++){
		scanf("%s",s+1); m=strlen(s+1);
		for (int j=1;j<m;j++) s[m+j]=s[j]; s[m*2]='\0';
		printf("%d\n",sam.getans(s));
	}
	
	return 0;
}