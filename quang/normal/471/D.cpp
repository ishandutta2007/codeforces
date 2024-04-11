#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 200010;
int n, w;
long long a[N], b[N];
int T[N];

int KMP()
{
    w--, n--;
    vector<int> T(w + 1, -1);
    int res = 0;
    for(int i = 1; i <= w; i++)
    {
        int pos = T[i - 1];
        while(pos != -1 && b[pos] != b[i - 1])
            pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < n)
    {
        while(kp != -1 && (kp == w || b[kp] != a[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == w) res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= w; i++) cin >> b[i];
    for(int i = 1; i <= n - 1; i++)
        a[i - 1] = a[i + 1] - a[i];
    for(int i = 1; i <= w - 1; i++)
        b[i - 1] = b[i + 1] - b[i];
    if(w == 1) cout << n;
    else
    cout << KMP();
    return 0;
}