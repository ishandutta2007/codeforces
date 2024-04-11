#include<bits/stdc++.h>
using namespace std;
int query(const string &s)
{
    printf("%s\n",s.c_str());
    fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res==0)exit(0);
    return res;
}
int main()
{
    int n=query("b")+1;
    int las=query(string(n-1,'a'));
    string str(n,'a');
    for(int i=0;i<n;i++)
    {
        str[i]='b';
        int now=query(str);
        if(now>las)str[i]='a';
        else las=now;
        if(las==n-i)
        {
            for(int j=i;j<n;j++)
                str[j]='a'+'b'-str[j];
            query(str);
        }
    }
    return 0;
}