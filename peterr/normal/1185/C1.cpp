#include <iostream>

using namespace std;

const int MAXN = 2 * 1E5;
const int MAXM = 2 * 1E7;
const int MAXT = 100;
int t[MAXN];
int freq[MAXT + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        int target = m - t[i];
        int j = 1;
        int numPass = 0;
        while (target > 0 && j <= MAXT)
        {
            if (freq[j] > 0)
            {
                int students = target / j;
                numPass += min(students, freq[j]);
                target = max(0, target - freq[j] * j);
            }
            j++;
        }
        cout << i - numPass << " ";
        freq[t[i]]++;
    }

    return 0;
}