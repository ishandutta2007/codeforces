#include <bits/stdc++.h>

using namespace std;
int w, n, el, x;
long long sum;
bool kul(int a, int b) {
    return (a>0)!=(b>0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> el, sum=el;
        for (int i=1; i<n; i++) {
            cin >> x;
            if (x>el && !kul(x, el)) sum+=x-el, el=x;
            else if (kul(x, el)) sum+=x, el=x;
        }
        cout << sum << "\n";
    }
    return 0;
}
// 1 5 1 -2 3 -4 5