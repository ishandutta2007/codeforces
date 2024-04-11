#include <bits/stdc++.h>

using namespace std;
long long n, h;
int s[200002];
int e[200002];
long long maxi;
long long p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    maxi=h;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        cin >> e[i];
    }
    int x=1, y=0;
    while(y<=n) {
        //cout << x << " " << y << " " << p << " " << h << endl;
        if (e[y]-s[x]>=h+p) {
            p-=e[x]-s[x];
            x++;
        } else {
            maxi=max(maxi, p+h);
            y++;
            p+=e[y]-s[y];
        }
    }
    cout << maxi << endl;
    return 0;
}