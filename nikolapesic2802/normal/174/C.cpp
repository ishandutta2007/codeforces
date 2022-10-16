#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int tr;
stack<int> l,r;
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%i",&x);
        while(tr<x)
        {
            l.push(i+1);
            tr++;
        }
        while(tr>x)
        {
            r.push(i);
            tr--;
        }
    }
    while(tr>0)
    {
        r.push(n);
        tr--;
    }
    printf("%i\n",l.size());
    while(!l.empty())
    {
        printf("%i %i\n",l.top(),r.top());
        l.pop();
        r.pop();
    }
    return 0;
}