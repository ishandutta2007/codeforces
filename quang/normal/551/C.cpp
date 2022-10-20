#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[100005], b[100005];

int check(long long k)
{
    for(int i = 1; i <= n; i++) b[i] = a[i];
    long long cp = k;
    int cur, ok;
    int sl = m;
    for(int i = n; i > 0; i--) if(b[i]) {cur = i; break;}
    if(k < cur) return 0;
    while(cur && sl)
    {
        ok = 0;
        while(cp && cur)
        {
            if(!ok){cp -= cur; ok = 1;}
            while(!b[cur] && cur) cur--;
            long long p = min(cp, b[cur]);
            cp -= p; b[cur] -= p;
        }
        cp = k;
        sl--;
    }
    while(!b[cur] && cur) cur--;
    return !cur;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long r = 1000000000000000;
    long long l = 0;
    while(r - l > 1)
    {
        long long g = (r + l) / 2;
        if(check(g)) r = g;
        else l = g;
    }
    cout << r;
}