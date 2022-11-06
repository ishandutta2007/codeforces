#include <cstdio>
#include <algorithm>
using namespace std;

void read(int& a){ scanf("%d",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

int n,d,h;

int main()
{
    read(n,d,h);
    if(n==2){
        puts("1 2");
        return 0;
    }
    if(n==3){
        if(h==1 && d==2){
            puts("1 2\n1 3");
        } else if(h==2 && d==2){
            puts("1 2\n2 3");
        } else puts("-1");
        return 0;
    }
    if(h<=d && d<=2*h){
        if(h==d){
            if(h==1){
                puts("-1"); return 0;
            }
            int i;
            for(i=2;i<=h+1;++i) printf("%d %d\n",i-1,i);
            for(i=h+2;i<=n;++i) printf("%d %d\n",2,i);
        } else {
            int i;
            for(i=2;i<=h+1;++i){
                printf("%d %d\n",i-1,i);
            }
            printf("1 %d\n",h+2);
            for(i=h+3;i<=d+1;++i){
                printf("%d %d\n",i-1,i);
            }
            for(i=d+2;i<=n;++i) printf("1 %d\n",i);
        }
    } else puts("-1");
    return 0;
}