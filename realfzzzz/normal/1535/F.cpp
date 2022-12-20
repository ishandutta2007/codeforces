#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
const int maxn=2e5+5;
int n,l;
char tmp[maxn],*s[maxn],ord[maxn];
struct trie{
	int sz=1,ch[maxn][26],cnt,pos[maxn],size[maxn];
	void dfs(int u){
		pos[u]=++cnt;
		size[u]=1;
		for(int i=0;i<26;i++) if(ch[u][i]){
			int v=ch[u][i];
			dfs(v);
			size[u]+=size[v];
		}
	}
}t1,t2,t3;
vector<int> vec[maxn];
vector<int> cur1[maxn],cur2[maxn];
long long ans=0;
vector<int> q1[maxn];
struct qr{
	int l,r,tp,id;
};
vector<qr> q2[maxn];
inline int lowbit(int x){
	return x&-x;
}
int c[maxn];
void modify(int x,int k){
	while(x<=t3.sz){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void solve(vector<int> vec){
	int m=vec.size();
	t2.sz=t3.sz=1;
	memset(t2.ch[0],0,sizeof(t2.ch[0]));
	memset(t3.ch[0],0,sizeof(t3.ch[0]));
	for(int i:vec){
		cur1[i].resize(l+1);
		for(int j=1;j<=l;j++){
			if(!t2.ch[cur1[i][j-1]][s[i][j]-'a']){
				memset(t2.ch[t2.sz],0,sizeof(t2.ch[0]));
				t2.ch[cur1[i][j-1]][s[i][j]-'a']=t2.sz++;
			}
			cur1[i][j]=t2.ch[cur1[i][j-1]][s[i][j]-'a'];
		}
		cur2[i].resize(l+2);
		for(int j=l;j>0;j--){
			if(!t3.ch[cur2[i][j+1]][s[i][j]-'a']){
				memset(t3.ch[t3.sz],0,sizeof(t3.ch[0]));
				t3.ch[cur2[i][j+1]][s[i][j]-'a']=t3.sz++;
			}
			cur2[i][j]=t3.ch[cur2[i][j+1]][s[i][j]-'a'];
		}
	}
	t2.cnt=t3.cnt=0;
	t2.dfs(0);
	t3.dfs(0);
	for(int i=1;i<=t2.sz;i++) vector<int>().swap(q1[i]);
	for(int i:vec) q1[t2.pos[cur1[i][l]]].push_back(t3.pos[cur2[i][1]]);
	for(int i=1;i<=t2.sz;i++) vector<qr>().swap(q2[i]);
	for(int i:vec){
		ans+=2ll*(m-1)+1337ll*(n-m);
		int ml=1;
		for(int j=1;j<=l;j++) if(j==l||s[i][j]>s[i][j+1]){
			int u=cur1[i][ml-1],v=cur2[i][j+1];
			q2[t2.pos[u]-1].push_back({t3.pos[v],t3.pos[v]+t3.size[v]-1,2});
			q2[t2.pos[u]+t2.size[u]-1].push_back({t3.pos[v],t3.pos[v]+t3.size[v]-1,-2});
			ans+=2;
			ml=j+1;
		}
	}
	for(int i=1;i<=t2.sz;i++){
		for(int j:q1[i]) modify(j,1);
		for(qr j:q2[i]) ans+=(query(j.r)-query(j.l-1))*j.tp;
	}
	for(int i=1;i<=t2.sz;i++) for(int j:q1[i]) modify(j,-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	s[1]=tmp;
	scanf("%s",s[1]+1);
	l=strlen(s[1]+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+l;
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l;j++) ord[j]=s[i][j];
		sort(ord+1,ord+l+1);
		int u=0;
		for(int j=1;j<=l;j++){
			if(!t1.ch[u][ord[j]-'a']) t1.ch[u][ord[j]-'a']=t1.sz++;
			u=t1.ch[u][ord[j]-'a'];
		}
		vec[u].push_back(i);
	}
	for(int i=1;i<t1.sz;i++) if(vec[i].size()) solve(vec[i]);
	printf("%lld\n",ans/2);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}