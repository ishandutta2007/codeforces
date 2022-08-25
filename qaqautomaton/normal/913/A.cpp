#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n<=30){
        printf("%d\n",m&((1<<n)-1));
    }
    else{
        printf("%d\n",m);
    }
    return 0;
}