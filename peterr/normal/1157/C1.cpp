#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;
    int cur = 0;
    string ans = "";
    while (right >= left)
    {
        if (arr[left] < arr[right])
        {
            if (arr[left] > cur)
            {
                ans += 'L';
                cur = arr[left];
                left++;
            }
            else if (arr[right] > cur)
            {
                ans += 'R';
                cur = arr[right];
                right--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (arr[right] > cur)
            {
                ans += 'R';
                cur = arr[right];
                right--;
            }
            else if (arr[left] > cur)
            {
                ans += 'L';
                cur = arr[left];
                left++;
            }
            else
            {
                break;
            }
        }
    }

    cout << ans.length() << endl << ans;

    return 0;
}