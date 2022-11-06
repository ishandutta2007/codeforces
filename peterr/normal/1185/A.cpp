#include <bits/stdc++.h>

using namespace std;

int main()
{
    int walkers[3];
    int d;
    for (int i = 0; i < 3; i++)
        cin >> walkers[i];
    cin >> d;
    sort(walkers, walkers + 3);
    cout << max(0, d - (walkers[2] - walkers[1])) + max(0, d - (walkers[1] - walkers[0]));
    return 0;
}