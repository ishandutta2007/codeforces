#include <bits/stdc++.h>
using namespace std;

string s;

int poz, pio;

int main()
{
    cin >> s;
    if (s.size()&1)
    {
        printf("-1\n");
        return 0;
    }
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='L')
            poz++;
        if (s[i]=='R')
            poz--;
        if (s[i]=='U')
            pio++;
        if (s[i]=='D')
            pio--;
    }
    printf("%d\n", (abs(pio)+abs(poz))/2);
    return 0;
}