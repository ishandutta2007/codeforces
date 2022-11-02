#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string str;
    cin>>str;
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(') a++;
        else b++;
    }
    if(a!=b) cout<<-1;
    else
    {
        int naw=0,ans=0;
        int bug=-1;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(') naw++;
            else naw--;
            if(naw<0&&bug==-1)
            {
                bug=i;
            }
            else if(bug>=0&&naw==0)
            {
                ans+=i-bug+1;
                bug=-1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}