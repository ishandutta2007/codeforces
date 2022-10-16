#include <bits/stdc++.h>

using namespace std;

long long n, k;
int a[1000];
vector <int> v;

int main() {
    cin >> n >> k;
    for (int i = 0; i < 63; i++)
        if (n & (1LL<<i))
            a[i+20]++, k--;
    if (k < 0)
        return cout << "No", 0;
    cout << "Yes" << endl;
    for (int i = 81; i >= 0 && k >= a[i]; i--)
        k -= a[i], a[i-1] += 2*a[i], a[i] = 0;
    for (int i = 80; i>=0; i--)
        for (int j = 0; j < a[i]; j++)
            v.push_back(i);
    while(k--)
    {
        int u = v.back(); v.pop_back();
        v.push_back(u-1), v.push_back(u-1);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i]-20 << " ";
    return 0;
}