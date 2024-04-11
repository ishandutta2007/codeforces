#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
int m;
vector<int> q;
long long sum;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum+=x;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<q.size(); i++) {
        cout << sum-v[n-q[i]] << "\n";
    }
    return 0;
}