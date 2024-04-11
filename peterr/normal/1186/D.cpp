#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int arr[MAXN];
bool canChange[MAXN];

int main()
{
    int n;
    cin >> n;
    long long curSum = 0;
    for (int i = 0; i < n; i++)
    {
        long double d;
        cin >> d;
        arr[i] = (int) floor(d);
        if (d != floor(d))
            canChange[i] = true;
        curSum += arr[i];
    }
    int index = 0;
    while (curSum < 0)
    {
        if (canChange[index])
        {
            arr[index]++;
            curSum++;
        }
        index++;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}