#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int res=0;
    for(int i=0;i<(int)s.size() && i<(int)t.size();i++)
    {
        if(s[i]!=t[i])break;
        else res++;
    }
    printf("%d\n",(int)s.size()+(int)t.size()-2*res);
    return 0;
}