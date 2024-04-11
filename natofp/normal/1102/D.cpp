#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    int a[3];
    memset(a,0,sizeof a);
    for(int i=0;i<n;i++)
    {
        a[s[i]-'0']++;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='2')
        {
            if(a[2]>n/3)
            {
                a[2]--;
                if(a[0]<n/3) {s[i]='0'; a[0]++;}
                else {s[i]='1'; a[1]++;}
            }
        }

    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            if(a[0]>n/3)
            {
                a[0]--;
                if(a[2]<n/3)
                {
                    a[2]++;
                    s[i]='2';
                }
                else
                {
                    a[1]++;
                    s[i]='1';
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(a[1]>n/3)
            {
                if(a[0]<n/3)
                {
                    a[1]--;
                    a[0]++;
                    s[i]='0';
                }
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            if(a[1]>n/3)
            {
                if(a[2]<n/3)
                {
                    a[1]--;
                    a[2]++;
                    s[i]='2';
                }
            }
        }
    }
    cout<<s;
    return 0;
}