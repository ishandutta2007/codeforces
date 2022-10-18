#include <bits\stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> Vint;

void solve(int n)
{
    int xp, yp, xv, yv;

    xp = n;
    cin >> yp >> xv >> yv;

    int who = -1;
    int Move = 1;
    while (xp != 0 || yp != 0 || xv != 0 || yv != 0)
    {
        int dp = xp - yp;
        int dv = xv - yv;

        if (dp == dv && xv > xp)
        {
            who = 1;
            break;
        }

        if (Move == 1)
        {
            if (xp + yp == 1)
            {
                who = 1;
                break;
            }
            if (yp == 0)
                xp--;
            else if (xp == 0)
                yp--;
            else if (dp > dv)
                xp--;
            else if (dp < dv)
                yp--;
        }
        else
        {
            if (xv <= 1 && yv <= 1)
            {
                who = 2;
                break;
            }

           // assert(Move == 2);
           // assert(xv != xp + 1 || yv != yp + 1);
            xv--;
            yv--;
        }

        Move ^= 1 ^ 2;
    }

    assert(who != -1);
    if (who == 1)
        printf("Polycarp\n");
    else
        printf("Vasiliy\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    while (cin >> n)
        solve(n);
}