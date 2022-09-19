#include <bits/stdc++.h>

using namespace std;
const int c=200005;
bool pr[c];
int w;
int n, q, t[c];
vector<int> spec;
vector<long long> sum[c];
multiset<long long> s[c];

void add(int a, long long b) {
    for (auto x:spec) {
        int m=a%x;
        s[x].erase(s[x].find(sum[x][m]));
        sum[x][m]+=b*x;
        s[x].insert(sum[x][m]);
    }
}
void calc() {
    long long maxi=0;
    for (auto x:spec) {
        auto it=s[x].end();
        it--;
        maxi=max(maxi, *it);
    }
    cout << maxi << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n >> q;
        for (int i=1; i<n; i++) {
            if (!pr[n/i] && n%i==0) {
                spec.push_back(i);
                sum[i].resize(i);
                for (int j=0; j<i; j++) {
                    sum[i][j]=0;
                    s[i].insert(0);
                }
            }
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            add(i, t[i]);
        }
        calc();
        for (int i=1; i<=q; i++) {
            int a, b;
            cin >> a >> b;
            add(a, b-t[a]);
            t[a]=b;
            calc();
        }
        for (int i=0; i<=n; i++) {
            s[i].clear(), sum[i].clear();
            t[i]=0;
        }
        spec.clear();
    }
    return 0;
}