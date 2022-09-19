#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long a, b, c;
    cin >> a >> b >> c;
    a = min(a, b + 1);
    b = min(b, a + 1);
    cout << a + b + c + c;
    return 0;
}