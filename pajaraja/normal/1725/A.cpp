#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main() {
    scanf("%lld %lld",&n,&m);
    if(m==1) printf("%lld",n-1);
    else printf("%lld",n*(m-1));
    return 0;
}