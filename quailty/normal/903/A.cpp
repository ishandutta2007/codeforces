#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        bool isok=0;
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                isok|=(3*i+7*j==x);
        printf("%s\n",(isok ? "YES" : "NO"));
    }
    return 0;
}