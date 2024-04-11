#include <cstdio>

using namespace std;

const int N = 1e5 + 500;

int t,n,sol = 0,x;

int main(){
    scanf("%d%d",&n,&t);
    while(n > 0){
        scanf("%d",&x);
        t -= x + 1;n--;
    }
    t++;
    if(t == 0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}