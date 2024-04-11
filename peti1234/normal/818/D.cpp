#include <bits/stdc++.h>

using namespace std;
int n, a;
vector<vector<int>> o(1000001);
vector<int> t;
int main()
{
    cin >> n >> a;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x==a) {
            t.push_back(i);
        } else {
            o[x].push_back(i);
        }
    }
    for (int i=1; i<=1000000; i++) {
        if (o[i].size()>=t.size()) {
            for (int j=0; j<t.size(); j++) {
                if (t[j]<o[i][j]) {
                    break;
                }
                if (j==t.size()-1) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
    if (t.size()==0) {
        if (a!=1) {
            cout << 1;
        } else {
        cout << 2;
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}