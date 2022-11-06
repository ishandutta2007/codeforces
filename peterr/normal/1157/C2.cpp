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
        if (arr[left] == arr[right])
        {
            if (arr[left] > cur)
            {
                int i = left;
                while (i + 1 < n && arr[i+1] > arr[i])
                {
                    i++;
                }
                int j = right;
                while (j - 1 > 0 && arr[j-1] > arr[j])
                {
                    j--;
                }

                if (i - left > right - j)
                {
                    for (int c = 0; c <= i - left; c++)
                    {
                        ans += 'L';
                    }
                }
                else
                {
                    for (int c = 0; c <= right - j; c++)
                    {
                        ans += 'R';
                    }
                }
            }
            break;
        }
        else if (arr[left] < arr[right])
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