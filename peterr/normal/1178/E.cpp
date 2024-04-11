#include <bits/stdc++.h>

using namespace std;

void update(char ch, int &a, int &b, int &c)
{
    if (ch == 'a')
        a++;
    else if (ch == 'b')
        b++;
    else
        c++;
}

int main()
{
    string s;
    cin >> s;
    int l = 1;
    int r = (int) s.length() - 2;
    vector<char> v;
    while (l < r)
    {
        int a, b, c;
        a = b = c = 0;
        update(s[l - 1], a, b, c);
        update(s[l], a, b, c);
        update(s[r], a, b, c);
        update(s[r + 1], a, b, c);
        if (a > 1)
            v.push_back('a');
        else if (b > 1)
            v.push_back('b');
        else
            v.push_back('c');
        l += 2;
        r -= 2;
    }
    for (int i = 0; i < (int) v.size(); i++)
        cout << v[i];
    if ((int) s.length() % 4 != 0)
        cout << s[l - 1];
    for (int i = (int) v.size() - 1; i >= 0; i--)
        cout << v[i];
    cout << endl;
    return 0;
}