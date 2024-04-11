#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll n;
int chk[1048576];

int main(){
    scanf("%lld", &n);
    int tmp = 1;
    while(tmp <= 1048570){
        chk[tmp] = chk[tmp+1] = 1;
        if(tmp % 2 == 1) tmp = (tmp+1) * 2;
        else tmp = (tmp + 1) * 2 - 1;
    }
    printf("%d", chk[n]);
}