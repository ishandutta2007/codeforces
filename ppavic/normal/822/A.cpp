#include <cstdio>
#include <algorithm>

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long int llint;

llint a,b,c,sol = 1;

int main(){
    scanf("%I64d %I64d",&a,&b);
    c = min(a,b);
    for(int i = 1;i<=c;i++)
        sol *= i;
    printf("%I64d\n",sol);
}