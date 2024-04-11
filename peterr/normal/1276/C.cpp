#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4E5;
int a[MAXN];

void update(int &r, int &c, int p, int q, vector<vector<int>> &mat)
{
    r = (r + 1) % p;
    c = (c + 1) % q;
    if(mat[r][c])
        c = (c + 1) % q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    vector<pair<int, int>> freq;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[i])
            j++;
        freq.push_back({j - i + 1, a[i]});
        i = j + 1;
    }
    sort(freq.begin(), freq.end());
    int ans = 0;
    int cutoff = 0;
    int bestP = 0;
    int sum = 0;
    int ptr = 0;
    for (int p = 1; p <= MAXN; p++)
    {
        while (ptr < (int) freq.size() && freq[ptr].first <= p)
        {
            sum += freq[ptr].first;
            ptr++;
        }
        if (sum + ((int) freq.size() - ptr) * p >= (long long) p * p)
        {
            int x = sum + ((int) freq.size() - ptr) * p;
            if (x / p * p > ans)
            {
                ans = x / p * p;
                cutoff = ptr;
                bestP = p;
            }
        }
    }
    int r, c;
    r = c = 0;
    int cnt = 0;
    int q = ans / bestP;
    vector<vector<int>> mat(bestP);
    for (int i = 0; i < bestP; i++)
        mat[i] = vector<int>(q);
    ptr = cutoff;
    while (cnt < ans && ptr < (int) freq.size())
    {
        cnt += bestP;
        for (int i = 0; i < bestP; i++)
        {
            mat[r][c] = freq[ptr].second;
            update(r, c, bestP, q, mat);
        }
        ptr++;
    }
    ptr = cutoff - 1;
    while (cnt < ans)
    {
        cnt++;
        if (freq[ptr].first == 0)
            ptr--;
        freq[ptr].first--;
        mat[r][c] = freq[ptr].second;
        update(r, c, bestP, q, mat);
    }
    cout << ans << endl << bestP << " " << q << endl;
    for (int i = 0; i < bestP; i++)
    {
        for (int j = 0; j < q; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
    return 0;
}