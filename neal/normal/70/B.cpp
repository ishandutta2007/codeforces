#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector <int> sents;
char str [10005];

inline bool end (char c)
{
    return c == '.' || c == '?' || c == '!';
}

int main ()
{
    scanf ("%d", &n);
    int length = 0;

    while (scanf ("%s", str) == 1)
    {
        length += strlen (str) + 1;

        if (end (str [strlen (str) - 1]))
        {
            sents.push_back (length - 1);
            length = 0;
        }
    }

    for (int i = 0; i < (int) sents.size (); i++)
        if (sents [i] > n)
        {
            puts ("Impossible");
            return 0;
        }

    int texts = 0;

    for (int i = 0; i < (int) sents.size (); i++)
    {
        length = sents [i];

        while (i + 1 < (int) sents.size () && length + 1 + sents [i + 1] <= n)
        {
            i++;
            length += 1 + sents [i];
        }

        texts++;
    }

    printf ("%d\n", texts);
    return 0;
}