#include <bits/stdc++.h>

using namespace std;
int w, n, x, y, l, a, b, ela, elb, sa, sb;
int t[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, x=1, y=n, l=0, a=0, b=0, ela=0, elb=0, sa=0, sb=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        while(x<=y) {
            l++;
            if (a<=b) {
                while(x<=y && sa<=elb) sa+=t[x], x++;
                ela=sa, a+=sa, sa=0;
            }
            else {
                while(x<=y && sb<=ela) sb+=t[y], y--;
                elb=sb, b+=sb, sb=0;
            }
        }
        cout << l << " " << a << " " << b << "\n";
    }
    return 0;
}