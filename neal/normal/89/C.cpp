#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAX = 5005;

int N, M;
string grid [MAX];
vector <int> left [MAX], right [MAX], up [MAX], down [MAX];

void init ()
{
    int r, c;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (grid [i][j] != '.')
            {
                r = i; c = j;

                do
                    c--;
                while (c > 0 && grid [r][c] == '.');

                left [i][j] = c > 0 && c <= M ? c : -1;
                r = i; c = j;

                do
                    c++;
                while (c <= M && grid [r][c] == '.');

                right [i][j] = c > 0 && c <= M ? c : -1;
                r = i; c = j;

                do
                    r--;
                while (r > 0 && grid [r][c] == '.');

                up [i][j] = r > 0 && r <= N ? r : -1;
                r = i; c = j;

                do
                    r++;
                while (r <= N && grid [r][c] == '.');

                down [i][j] = r > 0 && r <= N ? r : -1;
            }
}

inline void remove (int r, int c)
{
    if (left [r][c] != -1) right [r][left [r][c]] = right [r][c];
    if (right [r][c] != -1) left [r][right [r][c]] = left [r][c];
    if (up [r][c] != -1) down [up [r][c]][c] = down [r][c];
    if (down [r][c] != -1) up [down [r][c]][c] = up [r][c];
}

int simulate (int r, int c)
{
    init ();
    int count = 0;

    while (r > 0 && r <= N && c > 0 && c <= M)
    {
        remove (r, c);
        count++;

        if (grid [r][c] == 'L')
            c = left [r][c];
        else if (grid [r][c] == 'R')
            c = right [r][c];
        else if (grid [r][c] == 'U')
            r = up [r][c];
        else if (grid [r][c] == 'D')
            r = down [r][c];
    }

    return count;
}

int main ()
{
    scanf ("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        left [i] = vector <int> (M + 1, 0);
        right [i] = vector <int> (M + 1, 0);
        up [i] = vector <int> (M + 1, 0);
        down [i] = vector <int> (M + 1, 0);
    }

    char line [MAX];

    for (int i = 1; i <= N; i++)
    {
        scanf ("%s", line);
        grid [i] = " " + (string) line;
    }

    int most = -1, count = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (grid [i][j] != '.')
            {
                int points = simulate (i, j);

                if (points > most)
                {
                    most = points;
                    count = 1;
                }
                else if (points == most)
                    count++;
            }

    printf ("%d %d\n", most, count);
    return 0;
}