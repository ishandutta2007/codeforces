#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    int g = 0;
    scanf("%d%d",&n,&k);
    while(n--){
        int a;
        scanf("%d",&a);
        g = __gcd(g,a);
    }
    g = __gcd(g,k);
    printf("%d\n",k/g);
    for(int i=0;i<k;i+=g)
        printf("%d ",i);
}