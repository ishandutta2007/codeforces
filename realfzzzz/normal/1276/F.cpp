#include<algorithm>
#include<set>
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
char str[maxn];
struct sam{
	int last,sz,len[maxn*2],link[maxn*2];
	map<char,int> nxt[maxn*2];
	vector<int> ch[maxn*2];
	sam(){
		sz=1;
		last=0;
		len[0]=0;
		link[0]=-1;
	}
	int extend(char c){
		int cur=sz++;
		len[cur]=len[last]+1;
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
				while(p>=0&&nxt[p][c]==q){
					nxt[p][c]=clone;
					p=link[p];
				}
				link[q]=link[cur]=clone;
			}
		}
		return last=cur;
	}
	void build(){
		for(int i=1;i<sz;i++) ch[link[i]].push_back(i);
	}
}t1,t2;
int cur1[maxn],cur2[maxn];
int pos[maxn*2],dep[maxn*2];
vector<int> f;
void dfs1(int u){
	pos[u]=f.size();
	f.push_back(u);
	if(u) dep[u]=dep[t2.link[u]]+1;
	else dep[u]=1;
	for(int i=0;i<t2.ch[u].size();i++){
		dfs1(t2.ch[u][i]);
		f.push_back(u);
	}
}
int st[maxn*4][25],lg[maxn*4];
void st_init(){
	for(int i=0;i<t2.sz*2-1;i++) st[i][0]=i;
	for(int i=1;(1<<i)<t2.sz*2-1;i++) for(int j=0;j+(1<<i)-1<t2.sz*2-1;j++)
		if(dep[f[st[j][i-1]]]<dep[f[st[j+(1<<(i-1))][i-1]]]) st[j][i]=st[j][i-1];
		else st[j][i]=st[j+(1<<(i-1))][i-1];
	lg[1]=0;
	for(int i=2;i<=t2.sz*2-1;i++) lg[i]=lg[i/2]+1;
}
int rmq_query(int l,int r){
	int k=lg[r-l+1];
	if(dep[f[st[l][k]]]<dep[f[st[r-(1<<k)+1][k]]]) return st[l][k];
	else return st[r-(1<<k)+1][k];
}
int lca(int x,int y){
	if(pos[x]>pos[y]) swap(x,y);
	return f[rmq_query(pos[x],pos[y])];
}
struct cmp{
	bool operator ()(int a,int b){
		return pos[a]<pos[b];
	}
};
set<int,cmp> s[maxn*2];
typedef set<int,cmp>::iterator iter;
long long cnt[maxn*2];
void dfs2(int u){
	for(int i=0;i<t1.ch[u].size();i++){
		int v=t1.ch[u][i];
		dfs2(v);
		if(s[u].size()<s[v].size()){
			swap(s[u],s[v]);
			cnt[u]=cnt[v];
		}
		for(iter i=s[v].begin();i!=s[v].end();i++){
			iter it=s[u].upper_bound(*i);
			cnt[u]+=t2.len[*i];
			if(it==s[u].begin()) cnt[u]-=t2.len[lca(*i,*it)];
			else if(it==s[u].end()) cnt[u]-=t2.len[lca(*i,*(--it))];
			else{
				iter it2=it;
				it2--;
				cnt[u]-=t2.len[lca(*i,*it)];
				cnt[u]-=t2.len[lca(*i,*it2)];
				cnt[u]+=t2.len[lca(*it,*it2)];
			}
			s[u].insert(*i);
		}
		s[v].clear();
	}
}
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%s",str+1);
    n=strlen(str+1);
    cur1[0]=0;
    for(int i=1;i<=n;i++) cur1[i]=t1.extend(str[i]);
    t1.build();
    cur2[n+1]=0;
    for(int i=n;i>0;i--) cur2[i]=t2.extend(str[i]);
    t2.build();
    dfs1(0);
    st_init();
    for(int i=0;i<n;i++){
    	cnt[cur1[i]]=n-i-1;
    	s[cur1[i]].insert(cur2[i+2]);
	}
	dfs2(0);
	long long ans=2+cnt[0];
	for(int i=1;i<t1.sz;i++) ans+=t1.len[i]-t1.len[t1.link[i]];
	for(int i=1;i<t1.sz;i++) ans+=cnt[i]*(t1.len[i]-t1.len[t1.link[i]]);
	for(int i=1;i<t1.sz;i++) if(t1.len[i]!=n)
		ans+=t1.len[i]-t1.len[t1.link[i]];
	printf("%lld\n",ans);
    return 0;
}