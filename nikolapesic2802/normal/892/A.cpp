#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    long long suma=0;
    priority_queue<int> k;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        suma+=a;
    }
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        k.push(a);
    }
    long long x=0;
    x+=k.top();
    k.pop();
    x+=k.top();
    if(suma<=x)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}