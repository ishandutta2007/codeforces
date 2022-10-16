#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

const int inf = (int)1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    vector<string> friends = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

    string s;

    cin >> s;

    int cnt = 0;

    for (auto name : friends)
        for (size_t i = 0; i < s.size (); i++)
            if (s.substr (i, name.size ()) == name)
                cnt++;

    cout << (cnt == 1 ? "Yes" : "No") << endl;

    return 0;
}