#include<iostream>

using namespace std;
const int N = 5000 + 10;

int f[N], a[N], res[N];

int main()
{
    ios_base::sync_with_stdio(true);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int sum = a[i], j = i - 1;
        while (j != 0 && sum < res[j]) sum += a[j], j--;
        f[i] = f[j] + i - (j + 1);
        res[i] = sum;
    }
    cout << f[n] << endl;
    return 0;
}