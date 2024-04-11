#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> a, b;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x%2) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int sum=0, sa=a.size(), sb=b.size();
    for (int i=0; i<sa-sb-1; i++) {
        sum+=a[i];
    }
    for (int i=0; i<sb-sa-1; i++) {
        sum+=b[i];
    }
    cout << sum << "\n";
    return 0;
}