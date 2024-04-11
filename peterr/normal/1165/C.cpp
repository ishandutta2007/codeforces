#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int index = 0;
    string good = "";

    while (index < n)
    {
        char first = s[index++];
        good += first;
        while (index < n && s[index] == first)
            index++;
        if (index < n)
            good += s[index++];
    }

    if (good.length() % 2 == 1)
    {
        good = good.substr(0, good.length() - 1);
    }

    cout << (s.length() - good.length()) << endl;
    cout << good;

    return 0;
}