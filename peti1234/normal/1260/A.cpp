#include <bits/stdc++.h>

using namespace std;
int w, a, b, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        sum=0;
        cin >> a >> b;
        while(a>0) {
            int x=b/a;
            b-=x;
            sum+=x*x;
            a--;
        }
        cout << sum << "\n";
    }
    return 0;
}