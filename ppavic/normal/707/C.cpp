#include <cstdio>

using namespace std;

typedef long long int llint;
llint n,m,x,y,mi;




int main(){
    scanf("%I64d",&n);
    if(n==1 || n == 2) printf("-1\n");
    else if(n&1){
        printf("%I64d %I64d\n",(n*n+1)/2-1,(n*n+1)/2);
    }
    else{

        printf("%I64d %I64d\n",((n/2)*(n/2))-1,((n/2)*(n/2))+1);
    }
}