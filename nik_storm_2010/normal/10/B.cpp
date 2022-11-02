#include<iostream>
#include<cmath>

using namespace std;
const int N = 100;
int a[N+10][N+10];
int k,xm,ym;

int funct(int nom, int l, int leng)
{
    if (l + leng - 1 > k) return -1;
    int res = 0;
    for (int i = l; i <= l + leng - 1; i++)
    {
        if (a[nom][i] != 0) return -1;
        res = res + abs(nom - xm) + abs(i - ym);
    }
    return res;
}

void modify(int nom, int l, int leng)
{
    for (int i = l; i <= l + leng - 1; i++) a[nom][i] = 1;
}

int main()
{
    int n,q;
    cin >> n >> k;
    xm = (k+1) / 2; ym = (k+1) / 2;
    for (int test = 1; test <= n; test++)
    {
        cin >> q;
        int ans = -1, nom, l, r;
        for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++)
            {
                int cur = funct(i, j, q);
                if ((cur != -1) && ((ans == -1) || (cur < ans))) { ans = cur; nom = i; l = j; r = j + q - 1; }
            }
        if (ans == -1) cout << "-1" << endl; else
        {
            cout << nom << " " << l << " " << r << endl;
            modify(nom, l, r - l + 1);
        }
    }
    return 0;
}