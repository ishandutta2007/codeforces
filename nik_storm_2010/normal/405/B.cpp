#include<iostream>
#include<string>

using namespace std;
const int N = 5000;

bool used[N];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.') continue;
        if (s[i] == 'L')
        {
            int j = i;
            while (j >= 0) used[j] = true, j--;
            continue;
        }
        int j = i;
        while (j < n && s[j] != 'L') j++;
        if (j == n)
        {
            int j = i;
            while (j < n) used[j] = true, j++;
        }
        else
        {
            int o = j;
            while (i < j) used[i] = true, used[j] = true, i++, j--;
            i = o;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) if (!used[i]) ans++;
    cout << ans << endl;
    return 0;
}