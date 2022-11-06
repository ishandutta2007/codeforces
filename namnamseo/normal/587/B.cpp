#include <cstdio>
#include <algorithm>
using namespace std;
int ud[1000010], un;

int n,k;
int a [1000010];
long long l;

long long min(long long a,long long b){ return a<b?a:b; }

int ftree     [1000010];
int mdarr     [1000010];
int m=1000000007;

int sum(int x) {
    int ret=0;
    while(x) ret=(ret+ftree[x])%m, x&=(x-1);
    return ret;
}

void update(int pos,int v) {
    if(pos==0) return;
    while(pos<=1000001) ftree[pos]=(ftree[pos]+v)%m, pos+=(pos&(-pos));
}

int main()
{
    scanf("%d %I64d %d",&n,&l,&k);
    int i,j;
    for(i=0;i<n;++i) scanf("%d",a+i), ud[i]=a[i];
    sort(ud,ud+n);
    un=unique(ud,ud+n)-ud;
    for(i=0;i<n;++i) a[i]=lower_bound(ud,ud+un,a[i])-ud+1;
    int nn = min(l,n*k);
    int ans=0, md;
    int ind=0;
    int moi=l%n;
    long long leftc=l/n;
    for(i=0;i<nn;++i, ind=(ind+1)%n) {
        if(i<n) md=1;
        else md=sum(a[ind]);
        mdarr[i]=md;
        if(ind<moi){
            ans = (ans + ( 1LL * (leftc+1)%m*md )%m)%m;
        } else {
            ans = (ans + ( 1LL * (leftc)%m*md )%m)%m;
        }
        if(ind == (n-1)){
            for(j=i-n+1;j<=i;++j){
                update(a[j%n],mdarr[j]);
                if(j-n>=0) update(a[j%n],(m-mdarr[j-n])%m);
                //printf("%d : %d\n",a[j%n],mdarr[j]);
            }
            --leftc;
        }
    }
    printf("%d\n",ans);
    return 0;
}