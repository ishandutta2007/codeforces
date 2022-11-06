#include <cstdio>
#include <algorithm>

long long s1[100010];
long long s2[100010];

int main()
{
    int buf[100010];
    int i;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",buf+i);
    s1[0]=buf[0];
    for(i=1;i<n;i++) s1[i]=s1[i-1]+buf[i];
    std::sort(buf,buf+n);
    s2[0]=buf[0];
    for(i=1;i<n;i++) s2[i]=s2[i-1]+buf[i];
    int q;
    scanf("%d",&q);
    int a,b,c;
    long long ret;
    for(;q--;){
        scanf("%d%d%d",&a,&b,&c);
        b--; c--;
        if(a==1){
            ret=s1[c];
            if(b) ret-=s1[b-1];
        } else {
            ret=s2[c];
            if(b) ret-=s2[b-1];
        }
        printf("%I64d\n",ret);
    }
    return 0;
}