#include <bits/stdc++.h>
using namespace std;

int n;

int x;

vector <int> wek;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        while(!(x%2))
        x/=2;
        while(!(x%3))
        x/=3;
        wek.push_back(x);
    }
    sort(wek.begin(), wek.end());
    if (wek[0]==wek.back())
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}