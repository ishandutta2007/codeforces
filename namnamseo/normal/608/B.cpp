#include <cstdio>

char a[200010];
char b[200010];
int s[2][200010];
int l,m;

inline int count(int x,int y,int w) {
    return s[w][y]-s[w][x-1];
}

int main()
{
    scanf("%s%s",a+1,b+1);
    int i,j;
    for(l=1;a[l];++l); --l;
    for(m=1;b[m];++m); --m;
    for(i=1;i<=m;++i){
        s[0][i]=s[0][i-1];
        s[1][i]=s[1][i-1];
        ++s[b[i]-'0'][i];
    }
    long long ans=0;
    for(i=1;i<=l;++i){
        ans += count(i,i+m-l,1-a[i]+'0');
    }
    printf("%I64d\n",ans);
    return 0;
}