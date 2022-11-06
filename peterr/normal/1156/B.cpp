#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;

        int* freq = new int[26];
        fill(freq, freq + 26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq[(int) (s[i] - 'a')]++;
        }
        vector<char> letters;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
                letters.push_back((char) ('a' + i));
        }

        if (letters.size() == 1)
        {
            cout << s;
        }
        else if (letters.size() == 2)
        {
            if (abs(letters[0] - letters[1]) == 1)
            {
                cout << "No answer";
            }
            else
            {
                cout << s;
            }
        }
        else if (letters.size() == 3)
        {
            if (abs(letters[0] - letters[1]) != 1)
            {
                for (int i = 0; i < freq[letters[1] - 'a']; i++)
                    cout << letters[1];
                for (int i = 0; i < freq[letters[0] - 'a']; i++)
                    cout << letters[0];
                for (int i = 0; i < freq[letters[2] - 'a']; i++)
                    cout << letters[2];
            }
            else if (abs(letters[1] - letters[2]) != 1)
            {
                for (int i = 0; i < freq[letters[1] - 'a']; i++)
                    cout << letters[1];
                for (int i = 0; i < freq[letters[2] - 'a']; i++)
                    cout << letters[2];
                for (int i = 0; i < freq[letters[0] - 'a']; i++)
                    cout << letters[0];
            }
            else
            {
                cout << "No answer";
            }
        }
        else
        {
            vector<int> order;
            for (int i = 1; i < letters.size(); i += 2)
            {
                order.push_back(i);
            }
            for (int i = 0; i < letters.size(); i += 2)
            {
                order.push_back(i);
            }
            for (int index : order)
            {
                char c = letters[index];
                for (int i = 0; i < freq[(int) (c - 'a')]; i++)
                    cout << c;
            }

        }
        cout << endl;
    }
    return 0;
}