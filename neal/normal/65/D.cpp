#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 10005;
const char *HOUSES [] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

inline int map (char c)
{
    if (c == 'G') return 0;
    if (c == 'H') return 1;
    if (c == 'R') return 2;
    if (c == 'S') return 3;
    return -1;
}

struct hat
{
    int counts [4];

    inline hat (int a = 0, int b = 0, int c = 0, int d = 0)
    {
        counts [0] = a;
        counts [1] = b;
        counts [2] = c;
        counts [3] = d;
    }

    inline bool operator < (const hat &o) const
    {
        for (int i = 0; i < 4; i++)
            if (counts [i] != o.counts [i])
                return counts [i] < o.counts [i];

        return false;
    }
};

int N;
char str [MAXN];
set <hat> hats, next;

inline int next_house (hat h, char r)
{
    if (r != '?')
        return 1 << map (r);
    else
    {
        int least = MAXN;

        for (int i = 0; i < 4; i++)
            least = min (least, h.counts [i]);

        int mask = 0;

        for (int i = 0; i < 4; i++)
            if (h.counts [i] == least)
                mask |= 1 << i;

        return mask;
    }
}

int main ()
{
    scanf ("%d %s", &N, str);
    hats.insert (hat ());

    for (int n = 0; n < N; n++)
    {
        next.clear ();

        for (set <hat> :: iterator it = hats.begin (); it != hats.end (); it++)
        {
            int mask = next_house (*it, str [n]);

            for (int i = 0; i < 4; i++)
                if (mask & 1 << i)
                {
                    hat h = *it;
                    h.counts [i]++;
                    next.insert (h);
                }
        }

        hats = next;
    }

    int solution = 0;

    for (set <hat> :: iterator it = hats.begin (); it != hats.end (); it++)
        solution |= next_house (*it, '?');

    for (int i = 0; i < 4; i++)
        if (solution & 1 << i)
            puts (HOUSES [i]);

    return 0;
}