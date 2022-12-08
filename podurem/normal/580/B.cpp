#include <bits/stdc++.h>

using namespace std;

vector <pair <long long, long long> > a;

long long bin(long long x)
{
 long long g1 = 0, g2 = a.size() - 1;
 for (long long m = (g2 + g1) / 2; g2 - g1 != 1; m = (g2 + g1) / 2)
 if (a[m].first > x)
 g2 = m;
 else
 g1 = m;
 return g1;
}

int main()
{
 long long n, d;
 cin >> n >> d;
 a.resize(n + 1);
 a[n].second = 0;
 for (long long i = 0; i < n; i++)
 {
 cin >> a[i].first >> a[i].second;
 }
 sort(a.begin(), a.end() - 1);
 for (long long i = 1; i < n; i++)
 a[i].second = a[i - 1].second + a[i].second;
 long long ans = 0;
 for (long long i = 0; i < n; i++)
 {
 long long j = bin(a[i].first + d - 1);
 ans = max(ans, a[j].second - a[i - 1 + (n + 1) * (i == 0)].second);
 }
 cout << ans;
}