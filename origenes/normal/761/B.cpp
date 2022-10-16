#include <cstdio>
using namespace std;
int a[105], b[105], ad[105], bd[105];
int main(){
    int n, l;
    scanf("%d%d", &n, &l);
    if(n==1){
        printf("YES\n");
        return 0;
    }
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);
    for(int i=0; i<n-1; i++)
        ad[i]=a[i+1]-a[i];
    ad[n-1]=a[0]+l-a[n-1];
    for(int i=0; i<n-1; i++)
        bd[i]=b[i+1]-b[i];
    bd[n-1]=b[0]+l-b[n-1];
    for(int i=0; i<n; i++){
        bool flag=true;
        for(int j=0; j<n; j++)
            if(ad[(i+j)%n]!=bd[j]){
                flag=false;
                break;
            }
        if(flag){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}