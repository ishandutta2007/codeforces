#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s,a,b;
    cin>>s>>a>>b;
    bool isok[2]={0,0};
    for(int i=0;i<2;i++)
    {
        size_t idx=s.find(a);
        if(idx!=string::npos)
        {
            idx=s.find(b,idx+a.size());
            if(idx!=string::npos)isok[i]=1;
        }
        reverse(s.begin(),s.end());
    }
    if(isok[0] && isok[1])printf("both");
    else if(isok[0])printf("forward");
    else if(isok[1])printf("backward");
    else printf("fantasy");
    return 0;
}