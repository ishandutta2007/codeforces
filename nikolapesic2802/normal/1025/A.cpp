#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main()
{
    int n;
    scanf("%i",&n);
    if(n==1)
    {
        printf("Yes\n");
        return 0;
    }
    int color=0;
    while(n--)
    {
        char c;
        scanf(" %c",&c);
        if(color&(1<<(c-'a')))
        {
            printf("Yes\n");
            return 0;
        }
        else
        {
            color=color|(1<<(c-'a'));
        }
    }
    printf("No\n");
    return 0;
}