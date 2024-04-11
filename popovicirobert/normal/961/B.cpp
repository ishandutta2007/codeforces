#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;
int v[nmax],s[nmax],a[nmax],sa[nmax];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        cin >> v[i];
        s[i] = s[i-1] + v[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] == 1)
            sa[i] = sa[i-1] + v[i];
        else
            sa[i] = sa[i-1];
    }
    int sum = sa[n];
    int sol = 0;
    for(int i = k;i <= n;i ++)
    {
        int pret = sum - sa[i] + sa[i-k] + s[i] - s[i-k];
        sol = max(sol,pret);
    }
    cout << sol;
    return 0;
}