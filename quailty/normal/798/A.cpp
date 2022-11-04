#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool check(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    return t==s;
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        string t=s;
        for(int j=0;j<26;j++)
        {
            if(s[i]=='a'+j)continue;
            t[i]='a'+j;
            if(check(t))return 0*printf("YES");
        }
    }
    return 0*printf("NO");
}