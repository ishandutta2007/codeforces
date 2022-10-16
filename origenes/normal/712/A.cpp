#include <cstdio>
#include <cstring>
using namespace std;
int n;
int a[100002], b[100002];
int main(){
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=n-1; i>=0; i--){
        b[i]=a[i+1]+a[i];
    }
    for(int i=0; i<n; i++) printf("%d ", b[i]);
    printf("\n");
    return 0;
}