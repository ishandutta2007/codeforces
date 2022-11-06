#include <cstdio>

int n;
char buf[100010];

int main()
{
    scanf("%d%s",&n,buf);
    int i, lasti=0, x=0;
    int m2_cnt=0, m3_cnt=0;
    for(i=1;i<n;++i){
        if(buf[lasti]!=buf[i]){
            if(i-lasti>=2) ++m2_cnt;
            if(i-lasti>=3) ++m3_cnt;
            ++x;
            lasti=i;
        }
    }
    if(n-lasti>=2) ++m2_cnt;
    if(n-lasti>=3) ++m3_cnt;
    ++x;
    
    if(m2_cnt>=2 || m3_cnt){
        printf("%d\n",x+2);
    } else if(m2_cnt==1) printf("%d\n",x+1);
    else printf("%d\n",x);
    return 0;
}