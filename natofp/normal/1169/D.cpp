#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
string s;
string xxxxxx;

bool czy(int left,int right)
{
    for(int x=left;x<=right;x++)
    {
        for(int k=1;k<=15;k++)
        {
            if(x+2*k>right) break;
            if(s[x]==s[x+k] && s[x]==s[x+2*k]) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>xxxxxx;
    s='0'+xxxxxx;
    n=s.length()-1;
    long long int res=0;
    for(int left=1;left<=n;left++)
    {
        int right=left+2;
        if(right>n) continue;
        bool xd=false;
        while(right<=n)
        {
            bool ok = czy(left,right);
            if(ok)
            {
                xd=true;
                break;
            }
            else right++;
        }
        if(xd==false) continue;
        res+=n-right+1;
    }
    cout<<res<<endl;
    return 0;
}