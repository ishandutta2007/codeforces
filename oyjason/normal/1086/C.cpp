#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 3000200
using namespace std;
int read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int K,n,m,p[M],t1[M],t2[M],ans[40],vis[40];
char ch[M];

int fdmin(){
	for(int i=0;i<K;i++) if(vis[i]==-1) return i;
	return -1;
}

int fdmax(){
	for(int i=K-1;i>=0;i--) if(vis[i]==-1) return i;
	return -1;
}

int fd(int l,int r){
	for(int i=l+1;i<r;i++) if(vis[i]==-1) return i;
	return -1;
}

bool gt(int id){return vis[id]==-1;}

bool check1(int i){
	if(i==n+1) return true;
	if(ans[p[i]]==-1){
		int kk=fdmax();
		if(kk>t1[i]){vis[ans[p[i]]=kk]=p[i]; return true;}
		if(kk<t1[i]) return false; 
		vis[ans[p[i]]=t1[i]]=p[i];
		if(check1(i+1)) return true;
		vis[ans[p[i]]]=-1,ans[p[i]]=-1; return false;
	}
	else if(ans[p[i]]<t1[i]) return false;
	else if(ans[p[i]]>t1[i]) return true;
	else return check1(i+1);
}

bool check2(int i){
	if(i==n+1) return true;
	if(ans[p[i]]==-1){
		int kk=fdmin();
		if(kk<t2[i]){vis[ans[p[i]]=kk]=p[i]; return true;}
		if(kk>t2[i]) return false; 
		vis[ans[p[i]]=t2[i]]=p[i];
		if(check2(i+1)) return true;
		vis[ans[p[i]]]=-1,ans[p[i]]=-1; return false;
	}
	else if(ans[p[i]]>t2[i]) return false;
	else if(ans[p[i]]<t2[i]) return true;
	else return check2(i+1);
}

bool solve(){
	for(int i=1;i<=n;i++){
		if(ans[p[i]]>=0){
			if(ans[p[i]]<t1[i]||ans[p[i]]>t2[i]) return false;
			if(ans[p[i]]>t1[i]&&ans[p[i]]<t2[i]) return true;
			if(ans[p[i]]==t1[i]&&ans[p[i]]<t2[i]) return check1(i+1);
			if(ans[p[i]]==t2[i]&&ans[p[i]]>t1[i]) return check2(i+1);
			continue;
		}
		else if(t1[i]==t2[i]){
			if(!gt(t1[i])) return false;
			vis[ans[p[i]]=t1[i]]=p[i]; continue;
		}
		else{
			int kk=fd(t1[i],t2[i]);
			if(kk!=-1){vis[ans[p[i]]=kk]=p[i];return true;}
			if(gt(t1[i])){
				vis[ans[p[i]]=t1[i]]=p[i];
				if(check1(i+1)) return true; vis[ans[p[i]]]=-1; ans[p[i]]=-1;
			}
			if(gt(t2[i])){ 
				vis[ans[p[i]]=t2[i]]=p[i];
				if(check2(i+1)) return true; vis[ans[p[i]]]=-1;
			} 
			return false;
		} 
	} return true;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int T=read();T;--T){
		memset(ans,-1,sizeof(ans)),memset(vis,-1,sizeof(vis));
		K=read(),scanf("%s",ch+1),n=strlen(ch+1);
		for(int i=1;i<=n;i++) p[i]=ch[i]-'a';
		scanf("%s",ch+1); for(int i=1;i<=n;i++) t1[i]=ch[i]-'a';
		scanf("%s",ch+1); for(int i=1;i<=n;i++) t2[i]=ch[i]-'a';
		
	//	puts("");
	//	for(int i=1;i<=n;i++)printf("%d",p[i]); puts("");
	//	for(int i=1;i<=n;i++)printf("%d",t1[i]); puts("");
	//	for(int i=1;i<=n;i++)printf("%d",t2[i]); puts("\n");
		
		
		if(!solve()){puts("NO");continue;}
		
//		for(int i=0;i<K;i++) printf("%d %d\n",ans[i],vis[i]);
//		puts("");
		
		for(int i=0;i<K;i++) if(ans[i]==-1) vis[ans[i]=fdmin()]=i;
		puts("YES");
		for(int i=0;i<K;i++) putchar(ans[i]+'a'); putchar('\n'); 
	}
	return 0;
}