#include <iostream>
#include <string>

using namespace std;
const int ALPHA = 256;

int cnt[ALPHA];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int to = 0, d1 = s1.length(), d2 = s2.length();
    for (int i = 0; i < d1; i++) if (to != d2 && s1[i] == s2[to]) to++;
    if (to == d2)
    {
        cout << "automaton" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < d1; i++) cnt[s1[i]]++;
    for (int i = 0; i < d2; i++) cnt[s2[i]]--;
    for (int i = 0; i < ALPHA; i++) ok &= (cnt[i] >= 0);
    if (ok && d1 == d2)
    {
        cout << "array" << endl;
        return 0;
    }
    if (ok) cout << "both" << endl; else cout << "need tree" << endl;
    return 0;
}