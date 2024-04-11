#include <iostream>
#include <string>

using namespace std;
const int N = 150;

string base[N];
int leng[N], used[N];

bool compare(string s1, string s2)
{
    int n = s1.length();
    for (int i = 0; i < n; i++)
    {
        int c1 = s1[i];
        if ('a' <= c1) c1 -= 'a' - 'A';
        int c2 = s2[i];
        if ('a' <= c2) c2 -= 'a' - 'A';
        if (c1 != c2) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> base[i];
    for (int i = 1; i <= n; i++) leng[i] = base[i].length();
    string s;
    cin >> s;
    char c;
    cin >> c;
    int ds = s.length();
    for (int i = 0; i < ds; i++) for (int j = 1; j <= n; j++)
    {
        if (i + leng[j] > ds) continue;
        if (!compare(s.substr(i, leng[j]), base[j])) continue;
        for (int k = i; k < i + leng[j]; k++) used[k] = 1;
    }
    for (int i = 0; i < ds; i++) if (used[i])
    {
        char need = ('a' <= s[i]) ? c : c - 'a' + 'A';
        if (s[i] != need)
        {
            s[i] = need;
            continue;
        }
        if ('a' <= s[i])
        {
            for (char c = 'a'; c <= 'z'; c++) if (s[i] != c)
            {
                s[i] = c;
                break;
            }
        }
        else
        {
            for (char c = 'A'; c <= 'Z'; c++) if (s[i] != c)
            {
                s[i] = c;
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}