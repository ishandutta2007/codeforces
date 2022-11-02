#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    cout << "First" << endl;

    cout << max(max(a, b), c) - min(min(a, b), c) << endl;

    long long kcr;
    cin >> kcr;

    if(kcr == 1) a += max(max(a, b), c) - min(min(a, b), c);
    if(kcr == 2) b += max(max(a, b), c) - min(min(a, b), c);
    else if(kcr == 3) c += max(max(a, b), c) - min(min(a, b), c);

    if(a == c || b == c || a == b) return 0;

    long long x = max(max(a, b), c);
    long long sum = a + b + c;
    if(a == x) sum -= 3*a;
    if(b == x) sum -= 3*b;
    if(c == x) sum -= 3*c;

    cout << -sum << endl;

    cin >> kcr;
    if(kcr == 1) a -= sum;
    if(kcr == 2) b -= sum;
    else if(kcr == 3) c -= sum;

    if(a == c || b == c || a == b) return 0;

    cout << min(abs(a - c), abs(b - c)) << endl;


}