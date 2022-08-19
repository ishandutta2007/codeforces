#include <bits/stdc++.h>
using namespace std;

int n;

vector <int> wek;

int x;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        x=1;
        while(!wek.empty() && wek.back()==x)
        {
            wek.pop_back();
            x++;
        }
        wek.push_back(x);
    }
    for (int i=0; i<wek.size(); i++)
    {
        printf("%d ", wek[i]);
    }
    printf("\n");
    return 0;
}