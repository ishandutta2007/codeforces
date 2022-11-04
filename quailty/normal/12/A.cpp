#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a[3],s;
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    s=a[0]+a[1]+a[2];
    bool isok=1;
    for(int i=0;i<4;i++)
    {
        if(s[i]!=s[8-i])isok=0;
    }
    cout<<(isok ? "YES" : "NO")<<endl;
    return 0;
}