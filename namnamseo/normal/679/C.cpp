#include <cstdio>

int n,k;
char data[510][510];
int grp[510][510];
int par[510*510];
int cnt[510*510];
int sz [510*510];

int R(int x){ return (par[x]==x)?x:(par[x]=R(par[x])); }
void join(int a,int b){ a=R(a); b=R(b); if(a==b) return; sz[b]+=sz[a]; par[a]=b; }

int szs, inel;

void add(int a,int b){
    if(a<=0 || b<=0 || a>n || b>n) return;
    if(data[a][b]!='.') return;
    int x=R(grp[a][b]);
    if(cnt[x]==0) szs+=sz[x];
    ++cnt[x];
}

void rem(int a,int b){
    if(a<=0 || b<=0 || a>n || b>n) return;
    if(data[a][b]!='.') return;
    int x=R(grp[a][b]);
    --cnt[x];
    if(cnt[x]==0) szs-=sz[x];
}

int ans;
template<typename T> inline T max(T a, T b){ return a>b?a:b; }
template<typename T> inline T min(T a, T b){ return a<b?a:b; }

int main()
{
    scanf("%d%d",&n,&k);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%s",data[i]+1);
        for(j=1;j<=n;++j){
            if(data[i][j]=='X') continue;
            grp[i][j]=(i-1)*n+j;
            sz [grp[i][j]]=1;
            par[grp[i][j]]=grp[i][j];
            if(data[i][j-1]=='.') join(grp[i][j],grp[i][j-1]);
            if(data[i-1][j]=='.') join(grp[i][j],grp[i-1][j]);
            ans=max(ans, sz[R(grp[i][j])]);
        }
    }
    for(i=1; i<=n-k+1; ++i){
        int a,b;
        for(a=1; a<=k; ++a){
            for(b=1; b<=k; ++b){
                if(data[a+i-1][b]=='.') 
                    ++inel,
                    add(a+i-1,b);
            }
        }
        for(b=1;b<=k;++b){
            add(i-1,b);
            add(i+k,b);
        }
        for(a=1;a<=k;++a){ // right byun
            add(i+a-1,k+1);
        }
        ans=max(ans, szs+k*k-inel);

        for(j=2;j<=n-k+1;++j){
            for(a=1;a<=k;++a){
                if(data[a+i-1][j-1]=='.')   --inel;
                if(data[a+i-1][j+k-1]=='.') ++inel;
                
                rem(i+a-1,j-2);
                add(i+a-1,j+k);
            }
            rem(i-1,j-1);
            rem(i+k,j-1);
            
            add(i-1,j+k-1);
            add(i+k,j+k-1);
            
            ans=max(ans, szs+k*k-inel);
        }
        for(a=1;a<=k;++a){
            for(b=1;b<=k;++b){
                rem(i+a-1,n+1-b);
            }
        }
        inel=0;
        for(b=1;b<=k;++b){
            rem(i-1,n+1-b);
            rem(i+k,n+1-b);
        }
        for(a=1;a<=k;++a){
            rem(i+a-1,n-k);
        }
        szs=0;
    }
    printf("%d\n",ans);
    return 0;
}