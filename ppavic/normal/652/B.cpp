#include <cstdio>
#include <algorithm>

using namespace std;

int n,z[1005],sol[1005];


int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",&z[i]);
    sort(z,z+n);
    for(int i = 0;i<n;i+=2){
        sol[i] = z[i/2];
    }
    for(int i = 1;i<n;i+=2){
        sol[i] = z[n-(i/2)-1];
    }
    for(int i = 1;i<n;i++){
        if(i%2==1 && sol[i]<sol[i-1]){
            printf("Impossible");
            return 0;
        }
        if(i%2==0 && sol[i]>sol[i-1]){
            printf("Impossible");
            return 0;
        }
    }
    for(int i = 0;i<n;i++){
        printf("%d ",sol[i]);
    }
}