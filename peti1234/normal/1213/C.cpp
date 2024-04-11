#include <bits/stdc++.h>

using namespace std;
int w;
long long a, b, c, d, e, s[10], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            s[i]+=(i*j)%10;
        }
    }
    cin >> w;
    while(w--) {
        cin >> a >> b, c=a/b, d=c/10, e=c%10;
        sum=d*s[(b%10)];
        for (int i=1; i<=e; i++) {
            sum+=(b%10)*i%10;
        }
        cout << sum << "\n";
    }
    return 0;
}