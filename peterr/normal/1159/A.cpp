#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int imbalance = 0;
    int maxImbalance = 0;
    int plus = 0, minus = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
        {
            minus++;
            imbalance++;
            maxImbalance = max(imbalance, maxImbalance);
        }
        else
        {
            plus++;
            imbalance--;
        }
    }

    cout << (maxImbalance + plus - minus);
    return 0;
}