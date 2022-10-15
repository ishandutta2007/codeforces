#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
long long solve(int n, int m, vector<vector<long long>> a)
{

    /*for (long long i = 0; i < n; i++)
		for (long long j = 0; j < m; j++)
			cin >> a[i][j];*/
    long long sum = 0;

    //for (long long k = 0; k < 4; k++) {
    vector<long long> w(n), h(m);
    map<long long, int> s;
    for (long long i = 0; i < n; i++)
    {
        long long mn = a[i][0];
        for (long long j = 1; j < m; j++)
            mn += (a[i][j]);
        w[i] = mn;
        s[mn]++;
    }
    int cnt = 4;
    while (cnt && s.size())
    {
        auto it = s.rbegin();
        int cot = min(cnt, it->second);
        cnt -= cot;
        sum += it->first * cot;
        s.erase(it->first);
    }
    long long sum2 = 0;
    s.clear();
    for (long long i = 0; i < m; i++)
    {
        long long mn = a[0][i];
        for (long long j = 1; j < n; j++)
            mn += (a[j][i]);
        h[i] = mn;
        s[mn]++;
    }
    cnt = 4;
    while (cnt && s.size())
    {
        auto it = s.rbegin();
        int cot = min(cnt, it->second);
        cnt -= cot;
        sum2 += it->first * cot;
        s.erase(it->first);
    }

    sum2 = max(sum, sum2);
    sum = 0;
    for (long long k = 0; k < 4; k++)
    {
        vector<long long> w(n), h(m);
        for (long long i = 0; i < n; i++)
        {
            long long mn = a[i][0];
            for (long long j = 1; j < m; j++)
                mn += (a[i][j]);
            w[i] = mn;
        }
        for (long long i = 0; i < m; i++)
        {
            long long mn = a[0][i];
            for (long long j = 1; j < n; j++)
                mn += (a[j][i]);
            h[i] = mn;
        }
        long long mx = 0, mx_id = 0;
        for (long long i = 0; i < n; i++)
            if (w[i] > w[mx_id])
                mx_id = i;
        mx = w[mx_id];
        long long mx2 = 0, mx_id2 = 0;
        for (long long i = 0; i < m; i++)
            if (h[i] > h[mx_id2])
                mx_id2 = i;
        mx2 = h[mx_id2];
        if (mx > mx2)
        {
            for (long long j = 0; j < m; j++)
                a[mx_id][j] = 0;
        }
        else
        {
            for (long long j = 0; j < n; j++)
                a[j][mx_id2] = 0;
        }
        sum += max(mx2, mx);
    }
    return max(sum, sum2);
}
int main()
{
    long long n = 5, m = 5;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << solve(n, m, a);
    cin >> a[0][0];
}