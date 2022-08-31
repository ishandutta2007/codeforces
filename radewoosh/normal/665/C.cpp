#include <bits/stdc++.h>
using namespace std;

char wcz[1000007];

int tak[1000007];

int main()
{
    scanf("%s", wcz);
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        break;
        if (wcz[i]==wcz[i+1])
        {
            wcz[i+1]=1;
            tak[i+1]=1;
        }
    }
    for (int i=0; 1; i++)
    {
        if (!wcz[i])
        break;
        if (tak[i])
        {
            if (wcz[i-1]!='a' && wcz[i+1]!='a')
            {
                wcz[i]='a';
            }
            else
            {
                if (wcz[i-1]!='b' && wcz[i+1]!='b')
                {
                    wcz[i]='b';
                }
                else
                {
                    wcz[i]='c';
                }
            }
        }
        printf("%c", wcz[i]);
    }
    printf("\n");
    return 0;
}