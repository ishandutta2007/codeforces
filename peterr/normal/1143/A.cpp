#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int max0 = 0;
    int max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            max1 = i;
        }
        else
        {
            max0 = i;
        }
    }
    cout << min(max1, max0);
    return 0;
}