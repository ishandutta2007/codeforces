#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int n;
int main()
{

    scanf("%i",&n);
    int ax,ay,bx,by,cx,cy;
    scanf("%i %i %i %i %i %i",&ax,&ay,&bx,&by,&cx,&cy);
    if(bx>ax)
    {
        if(by>ay)
        {
            if(cx>ax&&cy>ay)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if(cx>ax&&cy<ay)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    else
    {
        if(by>ay)
        {
            if(cx<ax&&cy>ay)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if(cx<ax&&cy<ay)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}