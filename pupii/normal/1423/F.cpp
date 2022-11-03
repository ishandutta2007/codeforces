#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int N , K; cin >> N >> K; long long sum = 0 , sum1 = 0;
    for(int i = 1 ; i <= K ; ++i){int p , q; cin >> p >> q; sum += q; sum1 = (sum1 + 1ll * p * q) % N;}
    if(sum < N) puts("1");
    else if(sum == N) puts(sum1 % N == N * (N + 1ll) / 2 % N ? "1" : "-1");
    else puts("-1");
    return 0;
}