#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    int o=min(min(a,b-1),c-2);
    printf("%d\n",o*3+3);
}