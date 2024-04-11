#include <bits/stdc++.h>

using namespace std;

int freq[6];

int main()
{
    unordered_map<int, int> m;
    m[4] = 0;
    m[8] = 1;
    m[15] = 2;
    m[16] = 3;
    m[23] = 4;
    m[42] = 5;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int index = m[a];
        if (index == 0)
            freq[0]++;
        else if (freq[index] < freq[index - 1])
        {
            freq[index]++;
        }
    }
    int seq = *min_element(freq, freq + 6);
    cout << n - (seq * 6) << endl;
    return 0;
}