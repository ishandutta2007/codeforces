#include <bits/stdc++.h>

using namespace std;
const int c=1e6+5;
int w, n, d, ans[c];
bool t[c], v[c];
int solve(int a) {
    if (!t[a]) {
        return 0;
    }
    if (v[a]) {
        return ans[a];
    }
    v[a]=true;
    ans[a]=c;
    ans[a]=1+solve((a+d)%n);
    return ans[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> d;
        for (int i=0; i<n; i++) {
            cin >> t[i];
        }
        for (int i=0; i<n; i++) {
            if (!v[i]) {
                solve(i);
            }
        }
        int maxi=0;
        for (int i=0; i<n; i++) {
            maxi=max(maxi, ans[i]);
        }
        cout << (maxi>n ? -1 : maxi) << "\n";
        for (int i=0; i<n; i++) {
            t[i]=v[i]=ans[i]=0;
        }
    }
    return 0;
}