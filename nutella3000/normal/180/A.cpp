#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a;
    a.resize(n,-1);
    vector<int> b;
    for(int i = 0;i < m;i++) {
        int n1;
        cin >> n1;
        for(int i = 0;i < n1;i++) {
            int c;
            cin >> c;
            a[c - 1] = b.size();
            b.push_back(c - 1);
        }
    }
    int cl = 0;
    vector<pair<int,int>> ans;
    for(int i = 0;i < a.size();i++) if (a[i] == -1) cl = i;
    for(int i = 0;i < b.size();i++) {
        if (b[i] == i) continue;
        if (a[i] == -1) {
            ans.push_back(pair<int,int>(b[i] + 1,i + 1));
            cl = b[i];
            a[cl] = -1;
        }else {
            ans.push_back(pair<int,int>(i + 1,cl + 1));
            ans.push_back(pair<int,int>(b[i] + 1,i + 1));
            b[a[i]] = cl;
            a[cl] = a[i];
            cl = b[i];
            a[cl] = -1;
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0;i < ans.size();i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}