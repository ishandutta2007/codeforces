//CDQ && CDW AK IOI
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000100;
int n,k,cnt,ch[maxn][26],fail[maxn],id[maxn],el,head[maxn],to[maxn],nxt[maxn],dfs_clock,dfn[maxn],sz[maxn];
ll bit[maxn];
char str[maxn];
bool used[maxn];
inline void add(int u,int v){
    to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void insert(char *s,int x){
    int len=strlen(s),now=0;
    for(int i=0;i<len;i++){
        if(!ch[now][s[i]-'a']) ch[now][s[i]-'a']=++cnt;
        now=ch[now][s[i]-'a'];
    }
    id[x]=now;
}
void build_fail(){
    queue<int> q;
    for(int i=0;i<26;i++)
        if(ch[0][i]) q.push(ch[0][i]);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<26;i++)
            if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
            else ch[u][i]=ch[fail[u]][i];
    }
}
void build_tree(){
    for(int i=1;i<=cnt;i++) add(fail[i],i);
}
void dfs(int u=0){
    dfn[u]=++dfs_clock;sz[u]=1;
    for(int i=head[u];i;i=nxt[i]) dfs(to[i]),sz[u]+=sz[to[i]];
}
void update(int x,int v){
    for(int i=x;i<=dfs_clock;i+=i&-i) bit[i]+=v;
}
void update(int l,int r,int v){
    update(l,v);update(r+1,-v);
}
ll query(int x){
    ll sum=0;
    for(int i=x;i;i-=i&-i) sum+=bit[i];
    return sum;
}
ll query(char *s){
    int len=strlen(s),now=0;ll ans=0;
    for(int i=0;i<len;i++){
        now=ch[now][s[i]-'a'];
        ans+=query(dfn[now]);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++) scanf("%s",str),insert(str,i);
    build_fail();build_tree();dfs();
    for(int i=1;i<=k;i++) update(dfn[id[i]],dfn[id[i]]+sz[id[i]]-1,1),used[i]=true;
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        if(str[0]=='?') printf("%lld\n",query(str+1));
        else{
            int x=0,len=strlen(str);
            for(int i=1;i<len;i++) x=x*10+str[i]-'0';
            if(str[0]=='+'){
                if(used[x]) continue;
                update(dfn[id[x]],dfn[id[x]]+sz[id[x]]-1,1);
                used[x]=true;
            }
            else{
                if(!used[x]) continue;
                update(dfn[id[x]],dfn[id[x]]+sz[id[x]]-1,-1);
                used[x]=false;
            }
        }
    }
}