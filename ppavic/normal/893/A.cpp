#include <cstdio>

using namespace std;

int n,x;
int c1 = 1;
int c2 = 2;
int c3 = 3;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        if(c1 != x && c2 != x){
            printf("NO\n");return 0;
        }
        else if(c2 == x){
            c1 ^= c3;c3 ^= c1;c1 ^= c3;
        }
        else{
            c2 ^= c3;c3 ^= c2;c2 ^= c3;
        }
    }
    printf("YES\n");
}