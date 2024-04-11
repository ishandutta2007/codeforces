#include <bits/stdc++.h>

using namespace std;

int a[1005];
int ans[2];
int n;

int main()
{
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        ans[0] = 0;
        ans[1] = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int suma = 0;
        int sumb = 0;
        int cnt = 0;
        bool first = true;
        for (int i = 1, j = n; i <= j; )
        {
            if (first && suma <= sumb)
            {
                suma += a[i++];
                if (suma > sumb)
                {
                    cnt++;
                    ans[1] += sumb;
                    sumb = 0;
                    first = false;
                }
                continue;
            }
            if (!first && suma >= sumb)
            {
                sumb += a[j--];
                if (sumb > suma)
                {
                    cnt++;
                    ans[0] += suma;
                    suma = 0;
                    first = true;
                }
                continue;
            }
        }
        cnt += (suma && sumb);
        cout << cnt << " " << suma + ans[0] << " " << sumb + ans[1] << "\n";
    }
    return 0;
}