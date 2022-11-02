#include <iostream>
 
using namespace std;
 
int main()
{
    int n, m, cc, gc;
    long long int total = 0,dist;
    cin >> n >> m;
    cc = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> gc;
        dist = (n - cc + gc) % n;
        total += dist;
        cc = gc;
    }
    cout << total;
 
 
    return 0;
}