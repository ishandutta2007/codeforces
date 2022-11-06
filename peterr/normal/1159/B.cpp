#include <iostream>
#include <algorithm>

using namespace std;

bool check(int* m, int k, int n)
{
    int i = n;
    while (2 * i > n)
    {
        int kdistance = k * (i - 1);
        int numElements = n - i + 1;
        if (kdistance > m[numElements])
            return false;
        i--;
    }
    if (k * (i - 1) > m[n / 2 + 1])
        return false;

    return true;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int* m = new int[n / 2 + 2];
    m[1] = min(arr[1], arr[n]);
    for (int i = 2; i <= n / 2 + 1; i++)
    {
        m[i] = min(m[i-1], min(arr[i], arr[n - i + 1]));
    }

    int k = 0;
    for (int jump = 5e8; jump > 0; jump /= 2)
    {
        while((long long) (k + jump) * (n - 1) <= 1e9 && check(m, k + jump, n))
            k += jump;
    }

    cout << k;

    return 0;
}