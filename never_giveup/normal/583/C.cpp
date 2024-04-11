#include <bits/stdc++.h>

using namespace std;
int q[250000];
map<int, int> m;
int ans[500], k = 0;
int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
        cin >> q[i];
    sort(q, q + (n * n));
    for (int i = n * n - 1; i >= 0 && k < n; i--)
        if (m[q[i]] == 0){
            ans[k] = q[i];
            for (int j = 0; j < k; j++)
                m[__gcd(q[i], ans[j])] += 2;
            k++;
        }
        else
            m[q[i]]--;
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}