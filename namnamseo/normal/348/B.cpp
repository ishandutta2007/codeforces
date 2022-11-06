#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> edge[100010];
int n,m;

int parent[100010];
ll  size  [100010];
ll     tmp[100010];
ll     val[100010];
ll pending[100010];
int   ccnt[100010];

bool divzero=false;

ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

int visstack[100010];
int vistop;

void dfs(int pos){
    visstack[vistop++]=pos;
    int i,sz=edge[pos].size(),nxt;
    tmp[pos]=1;
    int& child=ccnt[pos];
    size[pos]=val[pos];
    for(i=0;i<sz;++i){
        nxt=edge[pos][i];
        if(nxt!=parent[pos]){
            parent[nxt]=pos;
            dfs(nxt);
            size[pos]+=size[nxt];
            tmp[pos]=lcm(tmp[pos],tmp[nxt]);
            ++child;
        }
    }
    if(child) tmp[pos]*=child;
}

ll totalmul=1LL<<62;

ll min(ll a,ll b){ return a>b?b:a; }

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i) scanf("%I64d",val+i);
    int a,b;
    m=n-1;
    for(;m--;){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b); edge[b].push_back(a);
    }
    parent[1]=-1;
    dfs(1);
    pending[1]=tmp[1];
    int j,sz,nxt,cur;
    for(i=0;i<vistop;++i){
        cur=visstack[i];
        sz=edge[cur].size();
        if(pending[cur]==0) divzero=true;
        else totalmul = min(totalmul,size[cur]/pending[cur]);
        for(j=0;j<sz;++j){
            nxt=edge[cur][j];
            if(parent[cur]!=nxt) {
                if(ccnt[cur]==0) divzero=true;
                else pending[nxt]=pending[cur]/ccnt[cur];
            }
        }
    }
    if(divzero) printf("%I64d\n",size[1]);
    else printf("%I64d\n",size[1]-tmp[1]*totalmul);
    return 0;
}