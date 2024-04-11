#include <cstdio>

using namespace std;

int n,cur,a[95];

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&cur);
        a[cur] = 1;
    }
    int last = 0;
    for(int i = 1;i<=90;i++){
        if(last == 15){
            printf("%d",i-1);
            return 0;
        }
        else if(a[i]){
            last = 0;
        }
        else{
            last++;
        }
    }
    printf("90");

}