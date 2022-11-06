#include <cstdio>

int n;
int data[100010];

bool bin[100010][20];
int sz  [100010];

bool st[20];
int top;

bool zero[100010];
int nonzind[100010];

int min(int a,int b){ return a>b?b:a; }

int main()
{
    scanf("%d",&n);
    int i,j;
    int ss=0;
    for(i=0;i<n;++i){
        scanf("%d",data+i);
        j=data[i];
        top=0;
        while(j) st[top++]=j&1, j>>=1;
        for(j=0;j<top;++j) bin[i][j]=st[top-1-j];
        sz[i]=top;
        zero[i]=true;
        ss+=top;
    }
    int cc[2];
    for(i=0;i<20;++i){
        cc[0]=cc[1]=0;
        for(j=0;j<n;++j) if(i<sz[j]) ++cc[bin[j][i]];
        if((cc[0]==0 || cc[1]==0) && (cc[0]+cc[1] == n)){
        } else break;
    }
    int k;
    for(j=0;j<n;++j){
        for(k=i;k<sz[j] && bin[j][k]==0;++k);
        nonzind[j]=k;
    }
    int ans=ss-i*j, cur;
    for(++i;i<20;++i){
        cur=0;
        for(j=0;j<n;++j){
            if(nonzind[j]<=i){
                cur+=sz[j]-nonzind[j] + (i-nonzind[j]);
            } else {
                cur+=sz[j]-i;
            }
        }
        ans=min(ans,cur);
    }
    printf("%d\n",ans);
    return 0;
}