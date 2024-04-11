#include <cstdio>
#include <vector>

int n;
int data[100010];

bool vis[100010];

int zeros[100010];
int zc;

int cycrep[100010];
int cycc;
int cc;

int left,right;

bool noa;

int maxsize;

int max(int a,int b){return a>b?a:b;  }

void dfs(int pos)
{
    vis[pos]=true;
    ++cc;
    int nxt=data[pos];
    if(vis[nxt]){
        if(pos==nxt){
            zeros[zc++]=pos;
        } else {
            if(cc&1) noa=1;
            else {
                if(cc==2 && left==0){
                    left=pos, right=nxt;
                } else cycrep[cycc++]=nxt;
            }
        }
    } else dfs(nxt);
}

int main()
{
    scanf("%d",&n);
    if(n==1){
        puts("YES"); return 0;
    }
    if(n==2){
        puts("YES\n1 2"); return 0;
    }
    int i;
    for(i=1;i<=n;++i)scanf("%d",data+i);
    for(i=1;i<=n;++i) if(!vis[i]){
        cc=0;
        dfs(i);
    }
    if(zc){
        int center=zeros[0];
        puts("YES");
        for(i=1;i<=n;++i) if(i!=center) printf("%d %d\n",i,center);
        return 0;
    }
    if(noa || left==0){
        puts("NO"); return 0;
    }
    puts("YES");
    printf("%d %d\n",left,right);
    int j, cur;
    for(i=0;i<cycc;++i){
        cur=cycrep[i];
        for(j=0;j==0 || cur!=cycrep[i];++j){
            printf("%d %d\n",cur,(j&1)?left:right);
            cur=data[cur];
        }
    }
    return 0;
}