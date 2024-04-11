#include <cstdio>
void read(int& a){ scanf("%d",&a); }
void read(long long& a){ scanf("%I64d",&a); }
void read(double& a){ scanf("%lf",&a); }
void read(char* a){ scanf("%s",a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int main()
{
    int a,b,c;
    read(a,b,c);
    int i;
    for(i=0;i<=c/a;++i){
        if((c-a*i)%b==0){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}