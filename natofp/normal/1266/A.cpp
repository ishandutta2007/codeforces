#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int ile[10];

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<10;j++) ile[j]=0;
        string s; cin>>s;
        int sum=0;
        for(int j=0;j<s.length();j++)
        {
            char akt=s[j];
            ile[akt-'0']++;
            sum+=(akt-'0');
        }
        if(sum%3!=0)
        {
            cout<<"cyan"<<endl;
            continue;
        }
        if(ile[0]>=2)
        {
            cout<<"red"<<endl;
            continue;
        }
        if(ile[0]==0)
        {
            cout<<"cyan"<<endl;
            continue;
        }
        if(ile[2]>0 || ile[4]>0 || ile[6]>0 || ile[8]>0)
        {
            cout<<"red"<<endl;
            continue;
        }
        cout<<"cyan"<<endl;

    }
    return 0;
}