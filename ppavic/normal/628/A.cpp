#include <cstdio>

using namespace std;

const int N = 505;

int a[N];
int n,b,p;

int po(int k){
    int z = 0;
    while((1 << z) <= k){
        z++;
    }
    return (1<<(z-1));
}

int main(){
    scanf("%d%d%d",&n,&b,&p);
    int sol1 = 0,sol2 = p*n;
    while(n != 1){
        int k = po(n);
        sol1 += k * b + (k/2);
        n -= k/2;

    }
    printf("%d %d\n",sol1,sol2);
}