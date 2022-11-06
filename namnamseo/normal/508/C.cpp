#include <cstdio>

int m,t,r;

bool array[2000];

int main()
{
    scanf("%d%d%d",&m,&t,&r);
    int i,j, backind;
    int w;
    int cnt=0;
    int ans=0;
    int needed;
    for(i=0;i<m;++i){
        scanf("%d",&w);
        w+=500;
        backind=w-1;
        needed=r;
        for(j=w;w-t<=j;--j) if(array[j]) --needed;
        for(j=0;j<needed;++j){
            if(w-backind>t){
                puts("-1");
                return 0;
            }
            if(array[backind]) {
                --backind; continue;
            }
            else {
                array[backind]=true;
                ++ans;
                --backind;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}