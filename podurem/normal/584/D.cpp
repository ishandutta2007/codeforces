#include <bits/stdc++.h>

using namespace std;

bool prost(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i <= trunc(sqrt(x)); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    int n, sum;
    cin >> n;
    vector <int> del;
    bool f = true;
    for (int i = 2; i <= n; i++)
        if (prost(i) && n == i && f)
            {cout << 1 << "\n" << i; f =false; break;}
        else
            if (prost(i) && prost(n - i) && f)
               {

                cout << 2 << "\n" << i << " " << n - i; f = false; break;}
            else
                if (prost(i) && prost((n - i) / 2) && (n - i) % 2 == 0 && f)
            {cout << 3 << "\n" << i << " " << (n - i) / 2 << " " << (n - i) / 2; f = false; break;}
}