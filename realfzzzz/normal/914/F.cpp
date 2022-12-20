#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,maxs=70,maxb=1620;
int n,q;
char s[maxn];
int S,B,L[maxb],R[maxb],pos[maxn];
struct SAM{
	int sz,last,len[maxs*2],link[maxs*2],nxt[maxs*2][26],cnt[maxs*2];
	vector<int> ch[maxs*2];
	void init(){
		sz=1;
		last=0;
		link[0]=-1;
		memset(nxt[0],0,sizeof(nxt[0]));
		cnt[0]=1;
	}
	void extend(int c){
		int cur=sz++;
		len[cur]=len[last]+1;
		memset(nxt[cur],0,sizeof(nxt[0]));
		cnt[cur]=1;
		int p=last;
		while(p>=0&&!nxt[p][c]){
			nxt[p][c]=cur;
			p=link[p];
		}
		if(p<0) link[cur]=0;
		else{
			int q=nxt[p][c];
			if(len[p]+1==len[q]) link[cur]=q;
			else{
				int clone=sz++;
				link[clone]=link[q];
				memcpy(nxt[clone],nxt[q],sizeof(nxt[0]));
				len[clone]=len[p]+1;
				cnt[clone]=0;
				while(p>=0&&nxt[p][c]==q){
					nxt[p][c]=clone;
					p=link[p];
				}
				link[cur]=link[q]=clone;
			}
		}
		last=cur;
	}
	void dfs(int u){
		for(int v:ch[u]){
			dfs(v);
			cnt[u]+=cnt[v];
		}
	}
}t[maxb];
char y[maxn];
int nxt[maxn];
void get_nxt(char* s,int n){
	int u=0;
	for(int i=2;i<=n;i++){
		while(u&&s[i]!=s[u+1]) u=nxt[u];
		if(s[i]==s[u+1]) u++;
		nxt[i]=u;
	}
}
int find(char* s,int n,char* t,int m){
	int u=0,cnt=0;
	for(int i=1;i<=m;i++){
		while(u&&t[i]!=s[u+1]) u=nxt[u];
		if(t[i]==s[u+1]) u++;
		if(u==n){
			cnt++;
			u=nxt[u];
		}
	}
	return cnt;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	S=max((int)sqrt(n/26),1);
	B=(n-1)/S+1;
	for(int i=1;i<=B;i++){
		L[i]=(i-1)*S+1;
		R[i]=min(n,i*S);
		t[i].init();
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
			t[i].extend(s[j]-'a');
		}
		for(int j=1;j<t[i].sz;j++) t[i].ch[t[i].link[j]].push_back(j);
		t[i].dfs(0);
	}
	q=readint();
	while(q--){
		int opt=readint();
		if(opt==1){
			int x=readint();
			scanf("%s",y);
			s[x]=y[0];
			t[pos[x]].init();
			for(int i=L[pos[x]];i<=R[pos[x]];i++) t[pos[x]].extend(s[i]-'a');
			for(int i=0;i<t[pos[x]].sz;i++) vector<int>().swap(t[pos[x]].ch[i]);
			for(int i=1;i<t[pos[x]].sz;i++)
				t[pos[x]].ch[t[pos[x]].link[i]].push_back(i);
			t[pos[x]].dfs(0);
		}
		else{
			int l,r;
			l=readint();
			r=readint();
			scanf("%s",y+1);
			int m=strlen(y+1);
			get_nxt(y,m);
			if(m>S||pos[l]==pos[r]){
				printf("%d\n",find(y,m,s+l-1,r-l+1));
				continue;
			}
			int ans=find(y,m,s+l-1,R[pos[l]]-l+1);
			for(int i=pos[l]+1;i<pos[r];i++){
				int u=0;
				bool ok=1;
				for(int j=1;j<=m;j++){
					if(!t[i].nxt[u][y[j]-'a']){
						ok=0;
						break;
					}
					u=t[i].nxt[u][y[j]-'a'];
				}
				if(ok) ans+=t[i].cnt[u];
			}
			ans+=find(y,m,s+L[pos[r]]-1,r-L[pos[r]]+1);
			if(pos[r]==pos[l]+1)
				ans+=find(y,m,s+max(l,R[pos[l]]-m+2)-1,min(R[pos[l]]-l+1,m-1)+min(r-L[pos[r]]+1,m-1));
			else{
				ans+=find(y,m,s+max(l,R[pos[l]]-m+2)-1,min(R[pos[l]]-l+1,m-1)+m-1);
				for(int i=pos[l]+1;i<pos[r]-1;i++) ans+=find(y,m,s+R[i]-m+1,m*2-2);
				ans+=find(y,m,s+R[pos[r]-1]-m+1,min(r-L[pos[r]]+1,m-1)+m-1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}