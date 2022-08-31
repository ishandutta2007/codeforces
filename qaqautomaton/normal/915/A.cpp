#include<bits/stdc++.h>
using namespace std;
void chkmin(int &a,int b){
    if(a>b)a=b;
}
int main(){
    int n,k,x,mn=23333;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if(!(k%x))chkmin(mn,k/x);
    }
    printf("%d\n",mn);
}