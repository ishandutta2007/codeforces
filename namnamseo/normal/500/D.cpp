#include <cstdio>

int nei;

int start[100010];
int  next[200010];
int   end[200010];
int   len[200010];
bool good[200010];

int curtime;

void aE(int a,int b,int l)
{
    nei++;
    next[nei]=start[a];
    start[a]=nei;
    end[nei]=b;
    len[nei]=l;
}

int n;

long long combi2(int x)
{
    return ((long long)x)*(x-1)/2;
}

long long combi3(int x)
{
    return ((long long)x)*(x-1)/2*(x-2)/3;
}

bool visited[100010];
int children[100010];

double origCost;

void buildTree(int pos)
{
    //printf("Visit %d\n",pos);
    visited[pos]=true;
    children[pos]=1;
    int cei = start[pos];
    int nxt;
    for(;cei!=0;cei=next[cei])
    {
        nxt=end[cei];
        if(!visited[nxt]){
            good[cei]=true;
            buildTree(nxt);
            //printf("From %d to %d(%d)\n",pos,nxt,children[nxt]);
            children[pos]+=children[nxt];
            origCost += 6.0*children[nxt]*(n-children[nxt])/n/(n-1)*len[cei];
        }
    }
}

int main()
{
    scanf("%d",&n);
    int a,b,l,i;
    for(i=1;i<n;++i){
        scanf("%d%d%d",&a,&b,&l);
        aE(a,b,l); aE(b,a,l);
    }
    curtime=5;
    origCost=0;
    buildTree(1);
    int q;
    scanf("%d",&q);
    int ta;
    //printf("Original %.6lf\n",origCost);
    for(;q--;)
    {
        scanf("%d%d",&ta,&b);
        //printf("%d th edge points to ",a);
        a=ta-1;
        a<<=1;
        ++a;
        if(!good[a]) ++a;
        //printf("%d\n",end[a]);
        origCost += 6.0*(b-len[a])*children[end[a]]*(n-children[end[a]])
                    /n/(n-1);
        //printf("Edge length from %d to %d\n",len[a],b);
        len[a]=b;
        len[((a-1)^1)+1]=b;
        printf("%.9lf\n",origCost);
    }
    return 0;
}