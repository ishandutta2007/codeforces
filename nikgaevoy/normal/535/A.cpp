#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio (false);

    int n;

    cin >> n;

    vector<string> num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                          "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                          "eighteen", "nineteen"};
    vector<string> ten = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (n < num.size ())
        cout << num[n] << endl;
    else
    {
        cout << ten[n / 10 - 2];

        if (n % 10 != 0)
            cout << "-" << num[n % 10];

        cout << endl;
    }

    return 0;
}