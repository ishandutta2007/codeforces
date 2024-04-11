#include <bits/stdc++.h>

using namespace std;
long long n, m;
vector<int> sz[100001];
vector<int> s[100001];
bool v[100001];
long long fix[100001];
int h[100001];
vector <int> me;
priority_queue<pair <long long, int>,vector<pair <long long, int>>, greater<pair <long long, int>> > k;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        sz[x].push_back(y);
        sz[y].push_back(x);
        s[x].push_back(z);
        s[y].push_back(z);
    }
    k.push({0, 1});
    while (!k.empty()) {
        if (v[k.top().second]) {
            k.pop();
        }
        else {
            int p=k.top().second;
            if (p!=1) {
                int i;
                for (i=0;!(v[sz[p][i]] && fix[sz[p][i]]+s[p][i]==k.top().first); i++);
                h[p]=sz[p][i];
            }
            v[p]=true;
            fix[p]=k.top().first;
            for (int i=0; i<sz[p].size(); i++) {
                k.push({fix[p]+s[p][i], sz[p][i]});
            }
            k.pop();
        }
    }
    if (fix[n]==0) {
        cout << -1 << endl;
        return 0;
    }
    //cout << fix[n] << endl;
    int x=n;
    me.push_back(x);
    while (h[x]!=0) {
        me.push_back(h[x]);
        x=h[x];
    }
    for (int i=me.size()-1; i>=0; i--) {
        cout << me[i] << " ";
    }

    return 0;
}