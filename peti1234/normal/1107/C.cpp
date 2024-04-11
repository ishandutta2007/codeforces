#include <bits/stdc++.h>

using namespace std;
int k, n;
vector<long long> v;
vector<long long> q[200001];
int c=1;
string s;
long long sum;
int main()
{
    cin >> k >> n;
    for (int i=0; i<k; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> s;
    q[1].push_back(v[0]);
    for (int i=1; i<k; i++) {
        if (s[i]!=s[i-1]) {
            c++;
        }
        q[c].push_back(v[i]);
    }
    for (int i=1; i<=c; i++) {
        sort(q[i].begin(), q[i].end());
        reverse(q[i].begin(), q[i].end());
    }
    for (int i=1; i<=c; i++) {
        int p=q[i].size();
        for (int j=0; j<min(p, n); j++) {
            sum+=q[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}