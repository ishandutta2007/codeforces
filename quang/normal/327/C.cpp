#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000007ll
#define N 100010

using namespace std;

string s;
int k, n;
long long res;

long long Pow(long long a,long long b){
    long long res = 1;
    for(long long i = a; b; b >>= 1, i = i * i % MAX)
        if(b & 1) res = res * i % MAX;
    return res;
}

int main() {
    //fi, fo;
    cin >> s;
    cin >> k;
    n = s.size();
    for(int i = 0; i < n; i++)
    if(s[i] == '0' || s[i] == '5') res = (res + Pow(2, i)) % MAX;
    res = res * (Pow(2, 1ll * k * n) - 1) % MAX;
    res = res * Pow(Pow(2, n) - 1, 1ll * MAX - 2) % MAX;
    cout << res;
    return 0;
}