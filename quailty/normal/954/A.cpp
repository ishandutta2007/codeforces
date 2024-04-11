#include<bits/stdc++.h>
using namespace std;
char str[105];
int main()
{
    int n,cnt=0;
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++)
    {
        if(str[i]!=str[i+1])i++;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}