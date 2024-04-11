#include <bits/stdc++.h>

using namespace std;

bool crossFree(bool** occupied, int row, int col)
{
    return !occupied[row][col] && !occupied[row-1][col] && !occupied[row+1][col] && !occupied[row][col-1] && !occupied[row][col+1];
}

void fillCross(bool** occupied, int row, int col)
{
    occupied[row][col] = true;
    occupied[row+1][col] = true;
    occupied[row-1][col] = true;
    occupied[row][col+1] = true;
    occupied[row][col-1] = true;
}

bool isPossible(bool** occupied, int sr, int er, int sc, int ec)
{
    if (sr > er)
        return true;
    if (sr == er && sc == ec)
        return occupied[sr][sc];
    if (!occupied[sr][sc] || !occupied[sr][ec] || !occupied[er][sc] || !occupied[er][ec])
        return false;
    for (int col = sc+1; col < ec; col++)
    {
        if (!occupied[sr][col])
        {
            if (crossFree(occupied, sr + 1, col))
            {
                fillCross(occupied, sr+1, col);
            }
            else
            {
                return false;
            }
        }

        if (!occupied[er][col])
        {
            if (crossFree(occupied, er - 1, col))
            {
                fillCross(occupied, er-1, col);
            }
            else
            {
                return false;
            }
        }
    }

    for (int row = sr + 1; row < er; row++)
    {
        if (!occupied[row][sc])
        {
            if (crossFree(occupied, row, sc+1))
            {
                fillCross(occupied, row, sc+1);
            }
            else
            {
                return false;
            }
        }

        if (!occupied[row][ec])
        {
            if (crossFree(occupied, row, ec-1))
            {
                fillCross(occupied, row, ec - 1);
            }
            else
            {
                return false;
            }
        }
    }

    return isPossible(occupied, sr+1, er-1, sc+1, ec-1);
}

int main()
{
    int n;
    cin >> n;
    bool** occupied = new bool*[n];
    for (int i = 0; i < n; i++)
    {
        occupied[i] = new bool[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                occupied[i][j] = false;
            else
                occupied[i][j] = true;
        }
    }

    if (isPossible(occupied, 0, n-1, 0, n-1))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}