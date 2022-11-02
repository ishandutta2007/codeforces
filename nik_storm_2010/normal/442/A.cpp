#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <fstream>

using namespace std;
const int N = 100 + 10;
const int ALPHA = 256;
const char a[11] = {'$', 'R', 'G', 'B', 'Y', 'W', '1', '2', '3', '4', '5'};

vector <string> s;
bool was[ALPHA], used[N];
int ans;

bool check(vector <string> x)
{

    int n = x.size(), colors, values, free = 0;
    if (n <= 1) return true;
    memset(was, false, sizeof(was));
    colors = values = 0;
    for (int i = 0; i < n; i++)
    {
        if (!was[x[i][0]]) colors++;
        if (!was[x[i][1]]) values++;
        was[x[i][0]] = true;
        was[x[i][1]] = true;
    }
    if (colors <= 1 && values <= 1) return true;
    bool go[n], ok = true;
    memset(go, false, sizeof(go));
    for (int i = 1; i <= 10; i++)
    {
        if (!used[i]) continue;
        int nom = (i <= 5) ? 0 : 1;
        vector <int> want;
        for (int j = 0; j < n; j++) if (go[j] == false && x[j][nom] == a[i]) want.push_back(j);
        if (want.size() == n) continue;
        vector <string> o;
        for (int j = 0; j < want.size(); j++) o.push_back(x[want[j]]), go[want[j]] = true;
        ok &= check(o);
    }
    if (!ok) return false;
    memset(was, false, sizeof(was));
    colors = values = 0;
    for (int i = 0; i < n; i++)
    {
        if (go[i]) continue;
        free++;
        if (!was[x[i][0]]) colors++;
        if (!was[x[i][1]]) values++;
        was[x[i][0]] = true;
        was[x[i][1]] = true;
    }
    if (colors <= 1 && values <= 1) return true;
    if (colors == 1 || values == 1)
    {
        int cnt = 0;
        vector <string> o;
        for (int j = 0; j < n; j++) if (go[j] == false)
        {
            o.push_back(s[j]);
            cnt++;
        }
        if (cnt == free) return false; else return check(o);
    }
    return false;
}

void build(int nom, int sum)
{
    if (nom == 11)
    {
        if (check(s)) ans = min(ans, sum);
        return;
    }
    used[nom] = false;
    build(nom + 1, sum);
    used[nom] = true;
    build(nom + 1, sum + 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string o;
        cin >> o;
        s.push_back(o);
    }
    ans = 2e9;
    build(1, 0);
    cout << ans << endl;
    return 0;
}