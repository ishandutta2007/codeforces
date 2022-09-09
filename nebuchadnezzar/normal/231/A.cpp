#include <iostream>

using namespace std;

int n, num1, num2, num3;

int main()
{
    cin >> n;
    int i, ans = 0;
    for(i = 0; i < n; ++i)
    {
        cin >> num1 >> num2 >> num3;
        if((num1 & num2) or (num2 & num3) or (num1 & num3) == 1)
        {
            ++ans;
        }
    }

                

    cout << ans;

    return 0;
}