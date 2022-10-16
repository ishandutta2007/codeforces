#include <cstdio>

using namespace std;

int q,n;

int main(){
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        scanf("%d",&n);
        if(n/4 <= 0 || (n % 4 == 1 && n/4-1<=0) || (n % 4 == 3 && n/4-2<=0)){
            printf("-1\n");
        }
        else if(n % 2){
            printf("%d\n",n/4-1);
        }
        else{
            printf("%d\n",n/4);
        }
            
    }
    
}