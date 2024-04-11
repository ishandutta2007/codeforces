#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 200005;
int bor[maxn * 32][2];
int8_t flags[maxn * 32];
int sz = 1;
 
void parse(const string s) {
    int fl = s[0] == '+' ? 1 : 2;
    uint64_t mask = 0;
    int len = 32;
    {
        stringstream ss(s);
        for (int i = 0; i < 4; ++i) {
            int tmp;
            ss >> tmp;
            if (i < 3) {
                char c;
                ss >> c;
            }
            mask = (mask << 8) + abs(tmp);
        }
 
        if (s.find('/') != string::npos) {
            char c;
            ss >> c;
            ss >> len;
        }
    }
 
    int cur = 0;
    for (int i = 0; i < len; ++i) {
        int to = (mask >> (31 - i)) & 1LL;
        if (bor[cur][to] == 0) {
            bor[cur][to] = sz++;
        }
        int ncur = bor[cur][to];
        flags[ncur] |= flags[cur];
        cur = ncur;
    }
    flags[cur] |= fl;
}
 
void dfs_push(const int v) {
    for (int i = 0; i < 2; ++i)
        if (bor[v][i] > 0) {
            flags[bor[v][i]] |= flags[v];
            dfs_push(bor[v][i]);
        }
}
 
void dfs(const int v) {
    for (int i = 0; i < 2; ++i)
        if (bor[v][i] > 0) {
            dfs(bor[v][i]);
            flags[v] |= flags[bor[v][i]];
        }
}
 
vector<string> result;
 
string GetMask(uint64_t mask, const int deep) {
    vector<int> result;
    for (int i = 0; i < 4; ++i) {
        result.push_back(mask & 255);
        mask >>= 8;
    }
    string ress;
    for (int i = 3; i >= 0; --i) {
        ress += to_string(result[i]);
        if (i > 0)
            ress += '.';
        else
            ress += '/';
    }
    return ress + to_string(deep);
}
 
void dfs_ans(const int v, const uint64_t mask = 0, const int deep = 0) {
    if (flags[v] == 2) {
        result.push_back(GetMask(mask, deep));
    } else {
        for(int i = 0; i < 2; ++i)
        if (bor[v][i] > 0 && flags[bor[v][i]] >= 2) {
            dfs_ans(bor[v][i], mask + i * (1LL << (31 - deep)), deep + 1);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        parse(std::move(s));
    }
 
    dfs_push(0);
        
    for(int i = 0; i < sz; ++i)
        if (flags[i] == 3) {
            cout << -1 << endl;
            return 0;
        }
 
 
    dfs(0);
    if (flags[0] >= 2)
        dfs_ans(0);
    cout << result.size() << endl;
    for (const auto& s : result)
        cout << s << '\n';
}