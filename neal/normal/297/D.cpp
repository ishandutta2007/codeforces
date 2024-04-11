#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1005;

int H, W, K;
char horiz[MAX][MAX], vert[MAX][MAX], color[MAX][MAX];
bool flipped = false;

void flip()
{
    char nhoriz[MAX][MAX], nvert[MAX][MAX];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W - 1; j++)
            nvert[j][i] = horiz[i][j];

    for (int i = 0; i < H - 1; i++)
        for (int j = 0; j < W; j++)
            nhoriz[j][i] = vert[i][j];

    memcpy(vert, nvert, sizeof(vert));
    memcpy(horiz, nhoriz, sizeof(horiz));

    for (int i = 0; i < max(H, W); i++)
        for (int j = i + 1; j < max(H, W); j++)
            swap(color[i][j], color[j][i]);

    swap(H, W);
}

void solve_row(int row)
{
    color[row][0] = '1';

    for (int i = 1; i < W; i++)
        if (horiz[row][i - 1] == 'E')
            color[row][i] = color[row][i - 1];
        else
            color[row][i] = '1' + '2' - color[row][i - 1];

    if (row == 0)
        return;

    int match = 0;

    for (int i = 0; i < W; i++)
        if (color[row][i] == color[row - 1][i] ^ vert[row - 1][i] == 'N')
            match++;

    if (2 * match < W)
    {
        for (int i = 0; i < W; i++)
            color[row][i] = '1' + '2' - color[row][i];
    }
}

int main()
{
    scanf("%d %d %d", &H, &W, &K);

    for (int i = 0; i < H; i++)
    {
        scanf("%s", horiz[i]);

        if (i < H - 1)
            scanf("%s", vert[i]);
    }

    if (K == 1)
    {
        int total = H * (W - 1) + (H - 1) * W;
        int equal = 0;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W - 1; j++)
                if (horiz[i][j] == 'E')
                    equal++;

        for (int i = 0; i < H - 1; i++)
            for (int j = 0; j < W; j++)
                if (vert[i][j] == 'E')
                    equal++;

        if (4 * equal >= 3 * total)
        {
            puts("YES");

            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    printf("%d%c", 1, j < W - 1 ? ' ' : '\n');
        }
        else
            puts("NO");

        return 0;
    }

    if (H > W)
    {
        flipped = true;
        flip();
    }

    for (int i = 0; i < H; i++)
        solve_row(i);

    if (flipped)
    {
        flipped = false;
        flip();
    }

    puts("YES");

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            printf("%c%c", color[i][j], j < W - 1 ? ' ' : '\n');

    return 0;
}