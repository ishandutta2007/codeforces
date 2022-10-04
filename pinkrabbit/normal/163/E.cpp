#include<cstdio>
#include<cstring>
// lgoj
int n,k;
char str[1000005];
int nx[1000005][26],cnt;
int id[100005];
void ins(int x,int y);
void Ins(int num,char*str){
    int now=0;
    for(int i=0;str[i];++i){
        if(!nx[now][str[i]-'a']) nx[now][str[i]-'a']=++cnt;
        now=nx[now][str[i]-'a'];
    } id[num]=now;
}
int fail[1000005],que[1000005],l,r;
void buildAC(){
    que[l=r=1]=0;
    while(l<=r){
        int u=que[l++];
        for(int i=0;i<26;++i) if(nx[u][i]){
            int x=fail[u];
            while(x&&!nx[x][i]) x=fail[x];
            if(u&&nx[x][i]) fail[nx[u][i]]=nx[x][i];
            ins(fail[nx[u][i]],nx[u][i]);
            que[++r]=nx[u][i];
        }
    }
}
int h[1000005],nxt[1000005],to[1000005],tot;
void ins(int x,int y){nxt[tot]=h[x];to[tot]=y;h[x]=tot++;}
int dfn[1000005],rdf[1000005],dfc;
void DFS(int u,int f=-1){
    dfn[u]=++dfc;
    for(int i=h[u];~i;i=nxt[i]) if(to[i]!=f) DFS(to[i],u);
    rdf[u]=dfc;
}
int b[1000005];
void Add(int i,int x){for(;i<=dfc;i+=i&-i)b[i]+=x;}
int Qur(int i){int S=0;for(;i;i-=i&-i)S+=b[i];return S;}
long long runAC(char*str){
    int now=0;
    long long sum=0;
    for(int i=0;str[i];++i){
        while(now&&!nx[now][str[i]-'a']) now=fail[now];
        if(nx[now][str[i]-'a']) now=nx[now][str[i]-'a'];
        sum+=Qur(dfn[now]);
    } return sum;
}
int v[1000005];
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i) scanf("%s",str), Ins(i,str);
    buildAC();
    DFS(0);
    for(int i=1;i<=k;++i) Add(dfn[id[i]],1), Add(rdf[id[i]]+1,-1) ,v[i]=1;
    char ch; int x;
    for(int i=1;i<=n;++i){
        while((ch=getchar())!='+'&&ch!='-'&&ch!='?');
        if(ch=='?'){
            scanf("%s",str);
            printf("%I64d\n",runAC(str));
            continue;
        }
        scanf("%d",&x);
        if(ch=='+'&&!v[x]) Add(dfn[id[x]],1), Add(rdf[id[x]]+1,-1), v[x]=1;
        if(ch=='-'&&v[x]) Add(dfn[id[x]],-1), Add(rdf[id[x]]+1,1), v[x]=0;
    }
    return 0;
}