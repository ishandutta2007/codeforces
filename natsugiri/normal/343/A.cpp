#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL calc(LL a, LL b) {
    if (a==0) return 0;
    if (a==b) return 1;
    return b/a + calc(b%a, a);
}

int main() {
    LL a, b;
    cin >> a >> b;
    cout << calc(a, b) << endl;

    return 0;
}