#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    //bool l=true;
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%i",&c);
        if(c==1)
        {
            printf("HARD\n");
            return 0;
        }
    }
    printf("EASY\n");
    return 0;
}