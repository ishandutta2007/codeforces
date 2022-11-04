#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
string str[105];
int main()
{
    string now;
    cin>>now;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>str[i];
    for(int i=1;i<=n;i++)
        if(now==str[i])return 0*printf("YES\n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(now[0]==str[i][1] && now[1]==str[j][0])
                return 0*printf("YES\n");
    return 0*printf("NO\n");
}