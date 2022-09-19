#include <bits/stdc++.h>

using namespace std;
long long n, m, k;
bool v[200001];
long long sum;
vector<pair<long long, long long> > t;

int main()
{
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t.push_back({-x, i});
    }
    sort(t.begin(), t.end());
    for (int i=0; i<m*k; i++) {
        long long fi=t[i].first;
        long long se=t[i].second;
        sum-=fi;
        v[se]=true;
    }
    cout << sum << endl;
    int y=0;
    for (int i=1; i<=n; i++) {
        if (v[i]) {
            y++;
            if (y%m==0 && y!=m*k) {
                cout << i << " ";
            }
        }
    }
    return 0;
}