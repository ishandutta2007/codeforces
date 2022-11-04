#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,string>p;
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    string a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        if(a.size()>b.size())p[a]=b;
        else p[a]=a;
    }
    string str;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        cout<<p[str]<<" ";
    }
    return 0;
}