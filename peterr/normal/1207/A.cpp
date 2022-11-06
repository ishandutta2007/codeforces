#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        if (h > c)
        {
            int hamburger = min(p, b / 2);
            ans += h * hamburger;
            b -= hamburger * 2;
            ans += c * min(f, b / 2);
        }
        else
        {
            int chicken = min(f, b / 2);
            ans += c * chicken;
            b -= chicken * 2;
            ans += h * min(p, b / 2);
        }
        cout << ans << endl;
    }
    return 0;
}