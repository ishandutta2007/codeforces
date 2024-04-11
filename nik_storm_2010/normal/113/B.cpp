#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>

using namespace std;
const int N = 1e5;

struct state
{
    bool ok;
    map <char, int> go;
    state() : ok(), go() { ok = false, go.clear(); }
};

char s[N], start[N], finish[N];
vector <state> tree;
int f[N], d_start[N], d_finish[N];

int main()
{
    string s, start, finish;
    getline(cin, s);
    getline(cin, start);
    getline(cin, finish);
    tree.push_back(state());
    int ds = s.length(), dstart = start.length(), dfinish = finish.length();
    string x = start + "$" + s;
    int dx = x.length(), k = 0;
    for (int i = 1; i < dx; i++)
    {
        while (k > 0 && x[k] != x[i]) k = f[k - 1];
        if (x[k] == x[i]) k++;
        f[i] = k;
        if (i > dstart) d_start[i - dstart - 1] = k;
    }
    x = finish + "$" + s;
    dx = x.length(), k = 0;
    for (int i = 1; i < dx; i++)
    {
        while (k > 0 && x[k] != x[i]) k = f[k - 1];
        if (x[k] == x[i]) k++;
        f[i] = k;
        if (i > dfinish) d_finish[i - dfinish - 1] = k;
    }
    int cnt = 1, ans = 0;
    for (int i = 0; i < ds; i++) for (int j = i, cur = 0; j < ds; j++)
    {
        if (tree[cur].go[s[j]] == 0)
        {
            tree[cur].go[s[j]] = cnt++;
            tree.push_back(state());
        }
        cur = tree[cur].go[s[j]];
        if (tree[cur].ok) continue;
        if (j - dfinish + 1 < i) continue;
        if (i + dstart - 1 > j) continue;
        if (d_start[i + dstart - 1] != dstart) continue;
        if (d_finish[j] != dfinish) continue;
        tree[cur].ok = true;
        ans++;
    }
    cout << ans << endl;
    return 0;
}