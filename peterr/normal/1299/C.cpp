#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
int a[MAXN];
long double ans[MAXN];
tuple<long long, int, int> st[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int tail = 0;
    st[tail++] = make_tuple(a[0], 1, 0);
    for (int i = 1; i < n; i++)
    {
        long long s = a[i];
        int l = 1;
        int ind = i;
        while (tail && get<0>(st[tail - 1]) * l >= s * get<1>(st[tail - 1]))
        {
            s += get<0>(st[tail - 1]);
            l += get<1>(st[tail - 1]);
            ind = get<2>(st[tail - 1]);
            tail--;
        }
        st[tail++] = make_tuple(s, l, ind);
    }
    int cur = n;
    for (int i = tail - 1; i >= 0; i--)
    {
        long long s = get<0>(st[i]);
        int l = get<1>(st[i]);
        int ind = get<2>(st[i]);
        long double avg = (long double) s / l;
        for (int j = ind; j < cur; j++)
            ans[j] = avg;
        cur = ind;
    }
    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(10) << ans[i] << "\n";
    }
    return 0;
}