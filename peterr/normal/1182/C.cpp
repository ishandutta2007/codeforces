#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
string strArr[MAXN];
tuple<int, int, string> words[MAXN];
vector<string> one;
vector<string> two;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        strArr[i] = s;
        pair<int, int> p = {0, 0};
        for (int j = 0; j < s.length(); j++)
        {
            char c = s[j];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                p.first++;
                p.second = c - 'a';
            }
        }
        words[i] = make_tuple(p.first, p.second, s);
    }
    sort(words, words + n);
    int firstPairs = 0, secondPairs = 0;
    int index = 0;
    while (index < n)
    {
        int unmatched = 0;
        int curVowels = get<0>(words[index]);
        while (index + 1 < n && get<0>(words[index + 1]) == curVowels)
        {
            if (get<1>(words[index]) == get<1>(words[index + 1]))
            {
                two.push_back(get<2>(words[index]));
                two.push_back(get<2>(words[index + 1]));
                secondPairs++;
                index += 2;
            }
            else
            {
                one.push_back(get<2>(words[index]));
                unmatched++;
                index++;
            }
        }
        if (index < n && get<0>(words[index]) == curVowels)
        {
            one.push_back(get<2>(words[index]));
            unmatched++;
            index++;
        }
        firstPairs += unmatched / 2;
        if (unmatched % 2 == 1)
            one.pop_back();
    }

    if (firstPairs >= secondPairs)
    {
        cout << secondPairs << endl;
        for (int i = 0; i < secondPairs; i++)
        {
            cout << one[i * 2] << " " << two[i * 2] << endl;
            cout << one[i * 2 + 1] << " " << two[i * 2 + 1] << endl;
        }
    }
    else
    {
        int k = (secondPairs - firstPairs + 1) / 2;
        for (int i = 0; i < k; i++)
        {
            one.push_back(two[two.size() - 1 - 2 * i]);
            one.push_back(two[two.size() - 2 - 2 * i]);
        }
        cout << secondPairs - k << endl;
        for (int i = 0; i < secondPairs - k; i++)
        {
            cout << one[i * 2] << " " << two[i * 2] << endl;
            cout << one[i * 2 + 1] << " " << two[i * 2 + 1] << endl;
        }
    }
    return 0;
}