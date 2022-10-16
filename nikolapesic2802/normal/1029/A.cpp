#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    string s;
    cin >> s;
    int broj=n;
    for(int i=1;i<n;i++)
    {
        bool t=true;
        for(int j=0;j<n-i;j++)
        {
            if(s[j]!=s[i+j])
            {
                t=false;
                break;
            }
        }
        if(t)
        {
            broj=i;
            break;
        }
    }
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<broj;j++)
        {
            printf("%c",s[j]);
        }
    }
    for(int j=0;j<n;j++)
    {
        printf("%c",s[j]);
    }
    printf("\n");
    return 0;
}