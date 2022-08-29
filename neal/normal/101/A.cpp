#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, K;
char line [MAXN];
pair <int, char> freq [100];

int main ()
{
    scanf ("%s", line);
    N = strlen (line);
    scanf ("%d", &K);

    for (int i = 0; i < N; i++)
        freq [(int) line [i] - 'a'].first++;

    for (int i = 0; i < 26; i++)
        freq [i].second = 'a' + i;

    sort (freq, freq + 26);
    int remove = 0, count = 0;

    for (int i = 0; i < 26; i++)
        if (K >= freq [i].first)
        {
            K -= freq [i].first;
            remove++;
        }

    for (int i = remove; i < 26; i++)
        if (freq [i].first > 0)
            count++;

    printf ("%d\n", count);

    for (int i = 0; i < N; i++)
    {
        bool bad = false;

        for (int j = 0; j < remove; j++)
            if (line [i] == freq [j].second)
                bad = true;

        if (!bad)
            putchar (line [i]);
    }

    putchar ('\n');
    return 0;
}