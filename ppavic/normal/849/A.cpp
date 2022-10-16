#include <cstdio>
#include <vector>

using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;

int a[N];


int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    if(n&1){
        if((a[0]&1) && (a[n-1]&1)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    else{
        printf("No\n");
    }
}