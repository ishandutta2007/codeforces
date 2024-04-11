#include<iostream>

using namespace std;
const int N = 1000 + 10;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1e9, nom;
    for (int first = 1; first <= 1000; first++)
    {
        int res = 0, x = first;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != x) res++;
            x += k;
        }
        if (res < ans) ans = res, nom = first;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != nom)
        {
            if (a[i] > nom) cout << "- " << i << " " << a[i] - nom << endl;
            if (a[i] < nom) cout << "+ " << i << " " << nom - a[i] << endl;
         }
         nom += k;
    }
    return 0;
}