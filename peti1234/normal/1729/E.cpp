#include <bits/stdc++.h>

using namespace std;
long long ask(int a, int b) {
    cout.flush() << "? " << a << " " << b << endl;
    long long x;
    cin >> x;
    return x;
}
void ans(long long x) {
    cout.flush() << "! " << x << endl;
    exit(0);
}
int main()
{
    for (int i=1; ; i++) {
        long long x=ask(i, i+1), y=ask(i+1, i);
        if (x==-1) ans(i);
        if (x!=y) ans(x+y);
    }
    return 0;
}