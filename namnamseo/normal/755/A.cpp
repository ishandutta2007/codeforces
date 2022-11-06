#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

bool isprime(int x){
    if(x==1) return false;
    for(int i=2; i*i<=x; ++i) if(x%i==0) return false;
    return 1;
}

int main()
{
    int n;
    read(n);
    for(int i=1; i<=1000; ++i){
        if(!isprime(n*i+1)){
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}