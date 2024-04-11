#include <bits/stdc++.h>

using namespace std;

struct Project
{
    int rating, change;
};

const int MAXN = 100;
const int MAXR = 30000;
Project pos[MAXN];
Project neg[MAXN];

int main()
{
    int n, r;
    cin >> n >> r;
    int len1 = 0, len2 = 0;
    for (int i = 0; i < n; i++)
    {
        Project p;
        cin >> p.rating >> p.change;
        if (p.change >= 0)
            pos[len1++] = p;
        else
            neg[len2++] = p;
    }
    sort(pos, pos + len1, [] (Project p1, Project p2) {return p1.rating < p2.rating;});
    bool valid = true;
    for (int i = 0; i < len1; i++)
    {
        //cout << pos[i].rating << endl;
        if (r >= pos[i].rating)
        {
            r += pos[i].change;
        }
        else
        {
            valid = false;
            break;
        }
    }
    if (valid && len2 > 0)
    {
        sort(neg, neg + len2, [] (Project p1, Project p2) {return p1.rating + p1.change < p2.rating + p2.change;});
        int req = max(0, neg[0].rating + neg[0].change);
        int minAmt = MAXR * 10;
        while (req <= MAXR * 2 + 5)
        {
            bool flag = true;
            int j = req;
            for (int k = 0; k < len2; k++)
            {
                if (j >= neg[k].rating + neg[k].change)
                    j -= neg[k].change;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                minAmt = min(minAmt, j);
            }
            req++;
        }
        if (r < minAmt)
            valid = false;
    }
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}