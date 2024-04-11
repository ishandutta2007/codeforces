#include <cstdio>

char a[100010];
char b[40];
int n,m;

int main()
{
    scanf("%s%s",a,b);
    for(;a[n];++n);
    for(;b[m];++m);
    int i,j;
    int ans=0;
    for(i=0;i<n-m+1;++i){
        for(j=0;j<m;++j){
            if(a[i+j]!=b[j]) break;
        }
        if(j==m){
            a[i+m-1]='#';
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}