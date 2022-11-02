#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int primes[100001];
    int div[100001];
    fill(primes, primes + 100001, 1);
    fill(div, div + 100001, 1);

    for(int i = 2; i<=100000; i++){
        if(div[i] == 1) div[i] = i;
        int x = 2*i;
        while(x <= 100000){
            primes[x] = 0;
            if(div[x] == 1) div[x] = i;
            x += i;
        }
    }

    int cnt = 0;
    for(int i = 2; i<=100000; i++){
        if(primes[i] == 1){
            cnt++;
            primes[i] = cnt;
        }
    }

    for(int i = 2; i<=n; i++){
        if(primes[i]) cout << primes[i] << " ";
        else cout << primes[div[i]] << " ";
    }

}