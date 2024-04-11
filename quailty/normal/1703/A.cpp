#include<bits/stdc++.h>
using namespace std;
int solve()
{
    char s[5];
    scanf("%s",s);
    bool isok=(s[0]=='Y' || s[0]=='y')
            &&(s[1]=='E' || s[1]=='e')
            &&(s[2]=='S' || s[2]=='s');
    return 0*printf("%s\n",isok ? "YES" : "NO");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}