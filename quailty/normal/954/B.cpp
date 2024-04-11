#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string str;
    cin>>n>>str;
    int res=n;
    for(int i=1;i+i<=n;i++)
        if(str.substr(0,i)==str.substr(i,i))
            res=n-i+1;
    printf("%d\n",res);
    return 0;
}