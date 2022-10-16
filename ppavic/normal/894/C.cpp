#include <cstdio>
#include <algorithm>

using namespace std;

int n,f;
int a[1005];

int main(){
    scanf("%d",&n);
    scanf("%d",&f);
    for(int i = 0;i<n-1;i++){
        scanf("%d",a+i);
        if(a[i]%f != 0){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n%d ",2*n-1,f);
    for(int i = 0;i<n-1;i++){
        printf("%d %d ",a[i],f);
    }
    printf("\n");
}