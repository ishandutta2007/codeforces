#include <iostream>
#include <algorithm>

using namespace std;

int binSearch(int* arr, int n, int key)
{
    if (key < arr[0])
        return -1;
    int index = 0;
    for (int jump = n / 2; jump > 0; jump /= 2)
    {
        while (index + jump < n && arr[index + jump] <= key)
            index += jump;
    }
    return index;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long pairs = 0;
    long long overcount = 0;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (a == 0)
            continue;
        int i1 = binSearch(arr, n, a);
        int i2 = binSearch(arr, n, 2 * a);
        int i3 = binSearch(arr, n, -a);
        int i4 = binSearch(arr, n, -2 * a);
        if (i3 != -1 && arr[i3] == -a && a < 0)
            overcount++;
        if (a > 0)
        {
            pairs += i2 - i1;
            if (i3 != -1)
            {
                if (i4 == -1 || arr[i4] < -2 * a)
                    i4++;
                pairs += i3 - i4 + 1;
            }
        }
        else
        {
            if (i2 == -1 || arr[i2] < 2 * a)
                i2++;
            pairs += i1 - i2;
            if (arr[i3] < -a)
            {
                i3++;
            }
            if (i3 < n)
            {
                pairs += i4 - i3 + 1;
            }
        }
    }

    cout << (pairs - overcount);

    return 0;
}