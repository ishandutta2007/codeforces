#include <cstdio>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int N, total = 0;
set <string> S;

int main ()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        string A = string (1, s1 [0]), B = string (1, s1 [1]), C = string (1, s2 [0]), D = string (1, s2 [1]);

        if (S.insert (A + B + D + C).second)
        {
            S.insert (B + D + C + A);
            S.insert (D + C + A + B);
            S.insert (C + A + B + D);
            total++;
        }

        if (i < N - 1)
            cin >> s1;
    }

    cout << total << '\n';
    return 0;
}