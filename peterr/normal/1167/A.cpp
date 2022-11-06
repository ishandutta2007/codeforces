#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n < 11)
            cout << "NO" << endl;
        else if (s.find("8") == string::npos)
            cout << "NO" << endl;
        else
        {
            int pos = s.find("8");
            if (pos + 10 < n)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}