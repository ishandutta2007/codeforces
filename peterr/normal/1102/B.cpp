#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int* freq = new int[5001];
    fill(freq, freq + 5001, 0);

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    if (*max_element(freq, freq + 5001) > k)
    {
        cout << "NO";
        return 0;
    }

    int* colors = new int[n];
    int c = 0;

    for (int i = 1; i < 5001; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                colors[j] = c+1;
                c = (c + 1) % (k);
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << colors[i] << " ";
    }

    return 0;
}