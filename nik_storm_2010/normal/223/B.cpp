#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 3e5;
const int ALPHA = 256;

char s[N], t[N];
vector <int> ps[ALPHA];
int left[N], right[N];

int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int ds = strlen(s), dt = strlen(t);
    for (int i = 0; i < dt; i++) ps[t[i]].push_back(i);
    for (int i = 0; i < ds; i++)
    {
        if (i == 0) left[i] = 0; else left[i] = left[i - 1];
        if (left[i] == dt) continue;
        if (s[i] == t[left[i]]) left[i]++;
    }
    for (int i = ds - 1; i >= 0; i--)
    {
        if (i == ds - 1) right[i] = 0; else right[i] = right[i + 1];
        if (right[i] == dt) continue;
        int need = dt - right[i] - 1;
        if (s[i] == t[need]) right[i]++;
    }
    for (int i = 0; i < ds; i++)
    {
        int before = (i == 0) ? 0 : left[i - 1];
        int later = (i == ds - 1) ? 0 : right[i + 1];
        if (ps[s[i]].size() == 0 || ps[s[i]][0] > before)
        {
            puts("No");
            return 0;
        }
        int l = 0, r = ps[s[i]].size();
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (ps[s[i]][m] <= before) l = m; else r = m;
        }
        if (later < dt - ps[s[i]][l] - 1)
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}