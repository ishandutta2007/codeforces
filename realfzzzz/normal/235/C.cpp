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
const int maxl=1e6+5;
int n,l;
char s[maxl];
int last,sz,len[maxl*2],link[maxl*2],cnt[maxl*2];
map<char,int> nxt[maxl*2];
vector<int> ch[maxl*2];
void init(){
	sz=1;
	last=0;
	len[0]=0;
	link[0]=-1;
	cnt[0]=1;
}
int extend(char c){
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
		if(len[q]==len[p]+1) link[cur]=q;
		else{
			int clone=sz++;
			len[clone]=len[p]+1;
			link[clone]=link[q];
			nxt[clone]=nxt[q];
			cnt[clone]=0;
			while(p>=0&&nxt[p][c]==q){
				nxt[p][c]=clone;
				p=link[p];
			}
			link[q]=link[cur]=clone;
		}
	}
	return last=cur;
}
void dfs(int u){
	for(int i=0;i<ch[u].size();i++){
		int v=ch[u][i];
		dfs(v);
		cnt[u]+=cnt[v];
	}
}
bool vis[maxl*2];
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%s",s);
    l=strlen(s);
    init();
    for(int i=0;i<l;i++) extend(s[i]);
    for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
    dfs(0);
    n=readint();
    while(n--){
    	scanf("%s",s);
    	l=strlen(s);
    	int u=0,cur=0;
    	for(int i=0;i<l;i++){
    		while(u>=0&&!nxt[u].count(s[i])){
    			u=link[u];
    			cur=len[u];
			}
			if(u<0){
				u=cur=0;
				continue;
			}
			u=nxt[u][s[i]];
			cur++;
		}
		long long ans=0;
		for(int i=0;i<l;i++){
    		while(u>=0&&!nxt[u].count(s[i])){
    			u=link[u];
    			cur=len[u];
			}
			if(u<0){
				u=cur=0;
				continue;
			}
			u=nxt[u][s[i]];
			cur++;
			if(cur>=l){
				while(len[link[u]]>=l) u=link[u];
				cur=l;
				if(!vis[u]){
					ans+=cnt[u];
					vis[u]=1;
				}
			}
		}
		printf("%lld\n",ans);
		u=cur=0;
    	for(int i=0;i<l;i++){
    		while(u>=0&&!nxt[u].count(s[i])){
    			u=link[u];
    			cur=len[u];
			}
			if(u<0){
				u=cur=0;
				continue;
			}
			u=nxt[u][s[i]];
			cur++;
		}
		for(int i=0;i<l;i++){
    		while(u>=0&&!nxt[u].count(s[i])){
    			u=link[u];
    			cur=len[u];
			}
			if(u<0){
				u=cur=0;
				continue;
			}
			u=nxt[u][s[i]];
			cur++;
			if(cur>=l){
				while(len[link[u]]>=l) u=link[u];
				cur=l;
				vis[u]=0;
			}
		}
	}
   return 0;
}