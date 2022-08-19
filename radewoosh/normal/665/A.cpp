#include <bits/stdc++.h>
using namespace std;

int a, b;
int c, d;

int e, f;

char wcz[107];

int sta, kon;

int wyn;

int main()
{
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);
    scanf("%s", wcz);
    sta+=(wcz[4]-'0')*1;
    sta+=(wcz[3]-'0')*10;
    sta+=(wcz[1]-'0')*60;
    sta+=(wcz[0]-'0')*600;
    kon=sta+b;
    for (int i=60*5; i<24*60; i+=c)
    {
        e=i;
        f=i+d;
        if (f<=sta || e>=kon)
        continue;
        wyn++;
    }
    printf("%d\n", wyn);
    return 0;
}