#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k, a, b, v;
    cin >> k >> a >> b >> v;
    for (int i = 1; i <= 100000; i++)
    {
        int all = min((k - 1) * i, b);
        if ((all + i) * v >= a)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}