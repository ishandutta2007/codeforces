#include <cstdio>

using namespace std;

bool check(int x){
    for(int k = 1;k<13;k++){
        if(((1<<k)-1) * (1<<(k-1)) == x) return true;
    }
    return false;
}

int n;

int main(){
    scanf("%d",&n);
    for(int i = n;i>=1;i--){
        if(n%i == 0 && check(i)){ printf("%d\n",i);return 0;}
    }
}