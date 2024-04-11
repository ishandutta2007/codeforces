#include <cstdio>

using namespace std;

const int N = 1e5 + 500;

int t,n,sol = 0,x;

int main(){
    scanf("%d%d",&n,&t);
    while(t > 0){
        scanf("%d",&x);
        t -= 86400 - x;sol++;
    }
    printf("%d\n",sol);
}