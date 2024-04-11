#include <cstdio>

using namespace std;

int a[105],n;


int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int z = 0;z<n;z++){
        int j = z-1;
        int i = z;
        if(j == -1) continue;
        while(a[i] < a[j]){
            printf("%d %d\n",j+1,i+1);
            int cnt = a[i];
            a[i] = a[j];
            a[j] = cnt;
            i--;
            j--;
            if(j == -1) break;
        }
    }
}