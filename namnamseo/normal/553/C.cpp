#include <cstdio>

int parent[100010];
int size  [100010];
int enemy [100010];

bool chk[100010];

int root(int r){return ((parent[r]==r)?r:(parent[r]=root(parent[r])));}

int join(int a,int b){
    if(a==0 || b==0) return a+b;
    a=root(a), b=root(b);
    if(a==b) return a;
    if(enemy[a]==b || enemy[b]==a) return -1;
    parent[a]=b;
    enemy[b]=join(enemy[a],enemy[b]);
    return b;
}

bool dis(int a,int b){
    a=root(a), b=root(b);
    if(a==b) return false;
    if(enemy[a]==b || enemy[b]==a) return true;
    if(enemy[a]) join(enemy[a],b);
    if(enemy[b]) join(enemy[b],a);
    enemy[a]=b, enemy[b]=a;
    return true;
}

int pow2(int x){
    if(x==0) return 1;
    if(x==1) return 2;
    int ret=pow2(x/2);
    ret=(ret*1LL*ret)      %1000000007;
    if(x&1) ret=(1LL*ret*2)%1000000007;
    return ret;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i) parent[i]=i, size[i]=1;
    int a,b,c;
    for(i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        if(c==0){
            if(!dis(a,b)){
                puts("0"); return 0;
            }
        } else {
            if(join(a,b)<0){
                puts("0"); return 0;
            }
        }
    }
    a=0;
    for(i=1;i<=n;++i){
        if(chk[root(i)]) continue;
        chk[root(i)]=true;
        if(enemy[root(i)]) chk[root(enemy[root(i)])]=true;
        ++a;
    }
    printf("%d\n",pow2(a-1));
    return 0;
}