#include <bits/stdc++.h>
using namespace std;

int n;
int k, a;

int m;
int x;

int ile;

set <int> secik;

set <int>::iterator it;

int pop, nas;

int wiel(int v)
{
    return (v+1)/(a+1);
}

int main()
{
    scanf("%d%d%d", &n, &k, &a);
    ile=wiel(n);
    secik.insert(0);
    secik.insert(n+1);
    scanf("%d", &m);
    for (int h=1; h<=m; h++)
    {
        scanf("%d", &x);
        it=secik.lower_bound(x);
        nas=(*it);
        it--;
        pop=(*it);
        ile-=wiel(nas-pop-1);
        ile+=wiel(x-pop-1);
        ile+=wiel(nas-x-1);
        secik.insert(x);
        if (ile<k)
        {
            printf("%d", h);
            return 0;
        }
    }
    printf("-1");
    return 0;
}