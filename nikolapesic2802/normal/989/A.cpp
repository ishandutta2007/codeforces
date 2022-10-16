#include <bits/stdc++.h>

using namespace std;

int main()
{
    //printf("%i  %i  %i %i",'.','A','B','C');
    char c[105];
    scanf("%s",c);
    string s=c;
    //printf("%i",s.size());
    for(int i=1;i<s.size()-1;i++)
    {
        if(s[i-1]+s[i+1]+s[i]=='A'+'B'+'C')
        {
            if(s[i-1]=='B'&&s[i]=='B'&&s[i+1]=='B')
            {

            }
            else
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}