#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    int mi = max(n - 2*m, 0LL);
    if(m == 0) mi = n;

    int ma = 0;
    for(long long i = 2; i<1000000; i++){
        if(m > (i*(i - 1)) / 2) ma = n - i - 1;
    }

    if(m == 0) ma = n;
    if(m == 1) ma = n - 2;

    cout << mi << " " << ma;

}