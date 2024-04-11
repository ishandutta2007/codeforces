#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

const int MAX=777;
vector<int> liczby(MAX,0);
bool czy[MAX][MAX];
bool dp[MAX][MAX][2];

void uzupelnij(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(gcd(liczby[i],liczby[j])>1) {czy[i][j]=1;}
            else czy[i][j]=0;
        }
    }
}

bool check(int a,int b,int who)
{
    for(int i=a;i<=b;i++)
    {
        if(dp[a][i][1]&&dp[i][b][0] && czy[i][who]) return true;
    }
    return false;
}

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        liczby[i]=x;
    }
    uzupelnij(n);
    for(int i=0;i<n;i++)
    {
        dp[i][i][0]=1;
        dp[i][i][1]=1;
    }
    for(int len=1;len<n;len++)
    {
        for(int i=0;(i+len)<n;i++)
        {
            dp[i][i+len][0]=check(i+1,i+len,i);
            dp[i][i+len][1]=check(i,i+len-1,i+len);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dp[0][i][1] && dp[i][n-1][0]) {cout<<"Yes"; return 0;}
    }
    cout<<"No";
    return 0;
}