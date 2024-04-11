#include <cstdio>
void read(int& a){ scanf("%d",&a); }
void read(long long& a){ scanf("%I64d",&a); }
void read(double& a){ scanf("%lf",&a); }
void read(char* a){ scanf("%s",a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int main()
{
    int n;
    read(n);
    int i,j;
    int cnt=0;
    int k=0;
    for(i=1;;++i){
        j=i;
        while(j%5==0) ++cnt, j/=5;
        if(cnt>n){
            puts("0"); return 0;
        } else if(cnt==n){
            puts("5");
            for(j=i;j<i+5;++j) printf("%d ",j);
            return 0;
        }
    }
    return 0;
}