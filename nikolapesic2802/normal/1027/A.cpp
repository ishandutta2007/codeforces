#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    for(int l=0;l<t;l++)
    {
        int n;
        scanf("%i",&n);
        string s;
        cin >> s;
        bool test=true;
        for(int i=0;i<n/2;i++)
        {
            int lol=abs(s[i]-s[n-1-i]);
            //printf("Gledam %c i %c\n",s[i],s[n-1-i]);
            if(lol==0||lol==2)
            {

            }
            else
            {
                test=false;
            }
        }
        if(test)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}