#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string s,t;
int dp[222][222][222];
int skad[222][222][222];
int n,m;

int reku(int a,int b,int bal)
{
    //cout<<a<<" "<<b<<" "<<bal<<endl;
    if(bal>210 || bal<0) return 1e9;
    if(a==0 && b==0) return bal;
    if(a>n && b>m) return 1e9;
    if(dp[a][b][bal]!=1e9) return dp[a][b][bal];
    if(a==0 || b==0)
    {
        int lewo=1e9;
        int prawo=1e9;
        if(a==0)
        {
            int xd;
            xd=b;

                if(t[xd-1]==')')
                {
                    xd--;
                    lewo=reku(0,xd,bal+1);
                }
                else lewo=reku(0,b,bal+1);

            xd=b;
            if(t[xd-1]=='(')
            {
                xd--;
                prawo=reku(0,xd,bal-1);
            }
            else prawo=reku(0,b,bal-1);
            dp[a][b][bal]=min(dp[a][b][bal],1+min(lewo,prawo));
        }
        else if(b==0)
        {
            int xd=a;

                if(s[xd-1]==')')
                {
                    xd--;
                    lewo=reku(xd,0,bal+1);
                }
                else lewo=reku(a,0,bal+1);

            xd=a;
            if(s[xd-1]=='(')
            {
                xd--;
                prawo=reku(xd,0,bal-1);
            }
            else prawo=reku(a,0,bal-1);

            dp[a][b][bal]=min(dp[a][b][bal],1+min(lewo,prawo));
        }
        return dp[a][b][bal];
    }
    int res=1e9;
    int pot1=1;
    if(true)
    {
        int xd1,xd2;
        xd1=a;
        xd2=b;
        if(xd1>0)
        {
            if(s[xd1-1]==')') xd1--;
        }
        if(xd2>0)
        {
            if(t[xd2-1]==')') xd2--;
        }
        pot1+=reku(xd1,xd2,bal+1);
        res=min(res,pot1);

    }
    if(bal>0)
    {
        int pot2=1;
        int xd1,xd2;
        xd1=a;
        xd2=b;
        if(xd1>0)
        {
        if(s[xd1-1]=='(') xd1--;
        }
        if(xd2>0)
        {
            if(t[xd2-1]=='(') xd2--;
        }
        pot2+=reku(xd1,xd2,bal-1);
        res=min(res,pot2);
    }
    dp[a][b][bal]=res;
    return res;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    for(int i=0;i<222;i++)
    {
        for(int j=0;j<222;j++)
        {
            for(int k=0;k<222;k++)
            {
                dp[i][j][k]=1e9;
            }
        }
    }
    string ans;
    int wyn=reku(n,m,0);
    int bal=0;
    for(int i=wyn;i>=1;i--)
    {
        if(bal==0)
        {
            ans+=")";
            bal++;
            if(s[n-1]==')') n--;
            if(t[m-1]==')') m--;
            continue;
        }
        int xd1=n;
        int xd2=m;
        if(s[n-1]==')') xd1--;
        if(t[m-1]==')') xd2--;
        if(dp[xd1][xd2][bal+1]==i-1)
        {
            n=xd1;
            m=xd2;
            bal++;
            ans+=")";
            continue;
        }
        else
        {
            xd1=n;
            xd2=m;
            if(s[n-1]=='(') xd1--;
            if(t[m-1]=='(') xd2--;
            n=xd1;
            m=xd2;
            bal--;
            ans+="(";
            continue;
        }
    }
    for(int i=wyn-1;i>=0;i--) cout<<ans[i];
    return 0;
}