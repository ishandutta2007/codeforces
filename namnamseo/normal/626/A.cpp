#include <cstdio>

char data[210];
int main()
{
    int n;
    scanf("%d%s",&n,data);
    int i,j;
    int ans=0;
    for(i=0;i<n;++i){
        for(j=0;j<=i;++j){
            int x=0,y=0,k;
            for(k=j;k<=i;++k){
                if(data[k]=='L') --y;
                if(data[k]=='D') ++x;
                if(data[k]=='U') --x;
                if(data[k]=='R') ++y;
            }
            if(x==0 && y==0) ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}