#include <iostream>

using namespace std;

int main()
{
    int freq[26];
    fill(freq, freq + 26, 0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        freq[name[0] - 'a']++;
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
        {
            freq[i]--;
            count += freq[i] / 2;
        }

        count += freq[i] / 2 * (freq[i] / 2 - 1);
    }

    cout << count;

    return 0;
}