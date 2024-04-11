#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct project {
    string name;
    int version;
    project() {
        name = "";
        version = 0;
    }
    project(string name, int version) {
        this->name = name;
        this->version = version;
    }
};

istream& operator>>(istream& i, project &a) {
    i >> a.name >> a.version;
    return i;
}

ostream& operator<<(ostream& o, const project &a) {
    o << a.name << ' ' << a.version;
    return o;
}

bool operator<(const project &a, const project &b) {
    if (a.name == b.name) return a.version < b.version;
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    project first;
    map<project, vector<project>> G;
    for (int i = 0; i < n; ++i) {
        project from;
        cin >> from;
        if (i == 0) first = from;
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            project to;
            cin >> to;
            G[from].push_back(to);
        }
    }
    map<string, int> ans;
    set<project> bfs;
    bfs.insert(first);
    while (bfs.size() > 0) {
        for (auto &i : bfs) ans[i.name] = i.version;
        map<string, int> newbfs;
        for (auto &i : bfs) 
            for (auto &j : G[i])
                if (!ans.count(j.name))
                    newbfs[j.name] = max(newbfs[j.name], j.version);
        bfs.clear();
        for (auto i : newbfs)
            bfs.insert(project(i.first, i.second));
    }
    cout << ans.size() - 1 << '\n';
    for (auto i : ans) 
        if (i.second != first.version || i.first != first.name)
            cout << i.first << ' ' << i.second << '\n';
    //system("pause");
    return 0;
}