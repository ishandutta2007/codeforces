#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

map < string, vector <string> > mp;

string str[22], aux;

bool cmp(string a, string b) {
    return a.size() < b.size();
}

vector <string> sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, m, j;
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        if(mp[str[i]].size() == 0)
            cnt++;
        cin >> m;
        for(j = 0; j < m; j++) {
            cin >> aux;
            mp[str[i]].push_back(aux);
        }
    }
    cout << cnt << endl;
    for(i = 1; i <= n; i++) {
        if(mp[str[i]].size() > 0) {
            sol.clear();
            cout << str[i] << " ";
            sort(mp[str[i]].begin(), mp[str[i]].end(), cmp);
            int sz = mp[str[i]].size();
            for(j = 0; j < sz; j++) {
                bool flag = 1;
                for(int p = j + 1; p < sz && flag; p++) {
                    int p1 = mp[str[i]][j].size() - 1, p2 = mp[str[i]][p].size() - 1;
                    while(p1 >= 0 && mp[str[i]][j][p1] == mp[str[i]][p][p2]) {
                        p2--;
                        p1--;
                    }
                    if(p1 == -1) {
                        flag = 0;
                    }
                }
                if(flag)
                    sol.push_back(mp[str[i]][j]);
            }
            cout << sol.size() << " ";
            for(auto it : sol)
                cout << it << " ";
            cout << endl;
            mp[str[i]].clear();
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}