#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[105],t[5];
        scanf("%s%s",s,t);
        int n=strlen(s);
        sort(s,s+n);
        int j=0;
        for(int i=0;i<n && j<3;i++)
            j+=(s[i]==t[j]);
        if(j==3)reverse(lower_bound(s,s+n,'b'),upper_bound(s,s+n,'c'));
        printf("%s\n",s);
    }
    return 0;
}