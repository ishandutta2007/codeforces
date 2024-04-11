#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, k, t[c], mini, maxi, sum;
void calc(long long a, int b) {
    sum+=b*max(a, t[a]);
}
void csere(int a, int b) {
    if (sum==k) {
        return;
    }
    calc(a, -1), calc(b, -1);
    swap(t[a], t[b]);
    calc(a, 1), calc(b, 1);
}
int main()
{
    cin >> n >> k;
    for (long long i=1; i<=n; i++) {
        t[i]=i;
        mini+=i, maxi+=max(i, n+1-i);
    }
    if (mini>k) {
        cout << -1 << "\n";
        return 0;
    }
    if (maxi<k) {
        cout << maxi << "\n";
        for (int i=1; i<=n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        for (int i=n; i>=1; i--) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << k << "\n";
    for (int i=1; i<=n; i++) {
        cout << i << " ";
    }
    cout << "\n";
    sum=mini;
    for (int i=1; sum<k; i++) {
        int s=n+1-i;
        csere(i, s);
        if (sum>k) {
            csere(i, s);
            for (int j=i; j<s; j++) {
                csere(j, j+1);
            }
            if (sum!=k) {
                for (int j=s-1; j>i; j--) {
                    csere(j, j-1);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}