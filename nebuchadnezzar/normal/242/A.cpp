#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int x, y, a, b, i, j;
vector <int> masa, masb;

int main()
{
    cin >> x >> y >> a >> b;
    int ans = 0;//(max(b + 1, a) - b) * (x - max(b + 1, a) + 1) + (x - max(b + 1, a)) * (x - max(b + 1, a) + 1) / 2;
    //cout << ans << endl;
    for(i = a; i <= x; ++i)
    {
        for(j = b; j <= y; ++j)
        {
            if(i > j)
            {
                masa.push_back(i);
                masb.push_back(j);
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    for(i = 0; i < masa.size(); ++i)
    {
        cout << masa[i] << " " << masb[i] << endl;
    }

    return 0;
}