#include <bits/stdc++.h>

using namespace std;
int solve(int a, int b) {
    if (a>=b) {
        return 0;
    }
    int po=1;
    while (po<=a) {
        po*=2;
    }
    int sum=0;
    sum+=b-b%po;
    b%=po;
    po/=2;
    return sum+solve(a-po, b-po);
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b+1) << "\n";
    }
    return 0;
}