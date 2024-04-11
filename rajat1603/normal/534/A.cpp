#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        printf("1\n1");
    }
    else if(n==2){
        printf("1\n1");
    }
    else if(n==3){
        printf("2\n1 3");
    }
    else if(n==4){
        printf("4\n2 4 1 3");
    }
    else{
        printf("%d\n",n);
        int k = n>>1;
        k+=n&1;
        for(int i=1;i<=k;++i){
            printf("%d ",(i<<1)-1);
        }
        for(int i=1;i<=k-(n&1);++i){
            printf("%d ",(i<<1));
        }
    }
}