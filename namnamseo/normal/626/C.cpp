#include <cstdio>
inline int max(int a,int b){ return a>b?a:b; }
inline int min(int a,int b){ return a>b?b:a; }
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int l=0, r=1e8, mid;
    while(l+1!=r){
        mid=(l+r)/2;
        if(mid/2>=n && mid/3>=m && mid/2+mid/3-mid/6>=n+m) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}