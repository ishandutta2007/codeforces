#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> s[100001];
int f[100001];
int maxi=0;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        s[a].push_back(-b);
    }
    for (int i=1; i<=m; i++) {
        sort(s[i].begin(), s[i].end());
    }
    for (int i=1; i<=m; i++) {
        for (int j=0; j<s[i].size(); j++) {
            s[i][j]*=-1;
        }
    }
    for (int i=1; i<=m; i++) {
        int sum=0;
        for (int j=0; j<s[i].size(); j++) {
            sum+=s[i][j];
            if (sum>0) {
                f[j+1]+=sum;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (f[i]>maxi) {
            maxi=f[i];
        }
    }
    cout << maxi << endl;
    return 0;
}