#include <cstdio>
#include <iostream>

using namespace std;


int n, l, r, sl, sr;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> l >> r;
        sl += l;
        sr += r;
    }
    cout << min(sl, n - sl) + min(sr, n - sr);


    return 0;
}