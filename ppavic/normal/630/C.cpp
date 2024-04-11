#include <cstdio>

using namespace std;

typedef unsigned long long int llint;

llint sol = 0,pot = 2;
int n;

int main(){
    scanf("%d",&n);
    for(; n ; n--, pot *= 2) sol += pot;
    printf("%I64d\n",sol);
}