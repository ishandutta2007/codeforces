#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>
//not my code
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(15);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        long long first, last, hp, dam, start, result, d;

        first = last = hp = dam = start = d = result = 0;
        cin >> n;
        result = 0;
        cin >> first >> last;
        start = pow(10, 12) + 1;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> hp >> dam;
            d = hp - last;
            if (d <= 0)
                start = min(start, hp);
            else
            {
                result += d;
                start = min(start, hp - d);
            }
            last = dam;
        }
        d = first - last;
        if (d <= 0) start = min(first, start);
        else
        {
            result += d;
            start = min(start, first - d);
        }

        result += start;
        cout << result << endl;
    }


    return 0;
}