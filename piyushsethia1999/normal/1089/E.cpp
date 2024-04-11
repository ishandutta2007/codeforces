#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

void printt(int i, int j)
{
    cout << (char)('a' + i) << j + 1 << " ";
}


int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int u = 0;
    int v = 0;
    printt(u, v);
    int k = 1, l = 0;
    if (n <= 56)
    {
        for (int i = 0; i < n - 2; ++i)
        {
            if (u == 7 && k == 1)
            {
                printt(u, v + 1);
                v++;
                k = -1;
            }
            else if (u == 0 && k == -1)
            {
                printt(u, v + 1);
                v++;
                k = 1;
            }
            else {
                u += k;
                printt(u, v);
            }
        }
        if (u == 7)
        {
            printt(7, v + 1);
            printt(7, 7);
        }
        else
        {
            printt(u, 7);
            printt(7, 7);
        }
    }
    else if (n <= 62) {
        for (int i = 0; i < 48; ++i)
        {
            if (u == 7 && k == 1)
            {
                printt(u, v + 1);
                v++;
                k = -1;
            }
            else if (u == 0 && k == -1)
            {
                printt(u, v + 1);
                v++;
                k = 1;
            }
            else {
                u += k;
                printt(u, v);
            }
        }
        n -= 48;
        k = 1;
        for (int i = 0; i < n - 2; ++i)
        {
            if (v == 7)
            {
                if (k == 1)
                {
                    k = -1;
                    u++;
                    printt(u, v);
                }
                else
                {
                    v += k;
                    printt(u, v);
                }
            }
            else if (v == 6)
            {
                if (k == 1)
                {
                    v += k;
                    printt(u, v);
                }
                else
                {
                    k = 1;
                    u++;
                    printt(u, v);
                }
            }
        }
        if (v == 7)
        {
            printt(6, 7);
            printt(7, 7);
        }
        else {
            if (k == 1)
            {
                printt(u, 7);
                printt(7, 7);
            }
            else
            {
                if (k == 1)
                {
                    printt(u, 7);
                    printt(7, 7);
                }
                else
                {
                    printt(7, 6);
                    printt(7, 7);
                }
            }
        }
    }
    else {
        for (int i = 0; i < 48; ++i)
        {
            if (u == 7 && k == 1)
            {
                printt(u, v + 1);
                v++;
                k = -1;
            }
            else if (u == 0 && k == -1)
            {
                printt(u, v + 1);
                v++;
                k = 1;
            }
            else {
                u += k;
                printt(u, v);
            }
        }
        n -= 48;
        k = 1;
        for (int i = 48; i < 59; ++i)
        {
            if (v == 7)
            {
                if (k == 1)
                {
                    k = -1;
                    u++;
                    printt(u, v);
                }
                else
                {
                    v += k;
                    printt(u, v);
                }
            }
            else if (v == 6)
            {
                if (k == 1)
                {
                    v += k;
                    printt(u, v);
                }
                else
                {
                    k = 1;
                    u++;
                    printt(u, v);
                }
            }
        }
        printt(7, 6);
        printt(6, 6);
        printt(6, 7);
        printt(7, 7);
    }

}