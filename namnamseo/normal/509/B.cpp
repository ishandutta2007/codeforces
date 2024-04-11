#include <cstdio>

int n,k;

int data[101];
bool dead[101];
int ans[101][101];
int index[101];

int min(int a,int b) { return a>b?b:a; }

int main()
{
    scanf("%d%d",&n,&k);
    int i,j;
    for(i=1;i<=n;++i) scanf("%d",data+i);
    int mval,mind, bef=0;
    int diff;
    int l;
    int left=n;
    mval=2e9;
    for(i=1;i<=n;++i) mval=min(mval,data[i]);
    for(i=1;i<=n;++i){
        for(j=0;j<mval;++j) ans[i][j]=1;
        if(data[i]>mval) ans[i][j++]=1;
        if(data[i]==j) dead[i]=true,--left;
        index[i]=j;
    }
    for(i=2;i<=k && left!=0;++i){
        for(j=1;j<=n;++j){
            if(!dead[j]){
                ans[j][index[j]++]=i;
                if(data[j]==index[j]) dead[j]=true, --left;
            }
        }
    }
    if(left) {
        puts("NO");
        return 0;   
    }
    puts("YES");
    for(i=1;i<=n;++i){
        for(j=0;j<data[i];++j) printf("%d ",ans[i][j]);
        putchar(10);
    }
    return 0;
}