#include<map>
#include<vector>
#include<cstring>
#include<cctype>
#include<cstdio>
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
const int maxn=1e5+5;
int n;
char s[maxn];
int sz,last,len[maxn*2],link[maxn*2],cnt[maxn*2];
map<char,int> nxt[maxn*2];
vector<int> ch[maxn*2];
void init(){
	sz=1;
	last=0;
	len[0]=0;
	link[0]=-1;
}
void extend(char c){
	int cur=sz++;
	len[cur]=len[last]+1;
	cnt[cur]=1;
	int p=last;
	while(p>=0&&!nxt[p].count(c)){
		nxt[p][c]=cur;
		p=link[p];
	}
	if(p<0) link[cur]=0;
	else{
		int q=nxt[p][c];
		if(len[p]+1==len[q]) link[cur]=q;
		else{
			int clone=sz++;
			len[clone]=len[p]+1;
			link[clone]=link[q];
			nxt[clone]=nxt[q];
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	last=cur;
}
void dfs(int u){
	for(int i=0;i<(int)ch[u].size();i++){
		int v=ch[u][i];
		dfs(v);
		cnt[u]+=cnt[v];
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s);
	n=strlen(s);
	init();
	for(int i=0;i<n;i++) extend(s[i]);
	for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	dfs(0);
	long long ans=0;
	for(int i=1;i<sz;i++) ans+=1ll*cnt[i]*(cnt[i]+1)/2*(len[i]-len[link[i]]);
	printf("%lld\n",ans);
	return 0;
}