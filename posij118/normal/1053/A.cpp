#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a < b) swap(a, b);
    if(b == 0) return a;

    else return gcd(a % b, b);
}

bool solve(long long n, long long m, long long k){

    long long nn, mm, kk;
    nn = n;
    mm = m;
    kk = k;

    long long p = n*m;
    long long d1 = gcd(n, k);
    n/=d1;
    k/=d1;

    long long d2 = gcd(m, k);
    m/=d2;
    k/=d2;

    if(k == 1 && 2*n <= nn){
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << 2*n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
        return 1;
    }

    else if(k == 1 && 2*m <= mm){
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << 2*m << endl;
        return 1;
    }

    else if(k == 2){
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << n << " " << 0 << endl;
        cout << 0 << " " << m << endl;
        return 1;
    }

    return 0;

}

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    if(!solve(n, m, k)) cout << "NO" << endl;
}