#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int n; n=s.length();
        vector<int> nxt(n+1);
        ll res=0;
        nxt[n]=n;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1') nxt[i]=i;
            else nxt[i]=nxt[i+1];
        }
        for(int i=0;i<n;i++)
        {
            int nast=nxt[i];
            if(nast==n) continue;
            int aktlen=nast-i+1;
            int val=1;
            //cout<<i<<" "<<aktlen<<endl;
            //if(i==2) cout<<res<<endl;
            if(val==aktlen) res++;
            for(int j=nast+1;j<min(n,nast+23);j++)
            {
                aktlen++;
                val*=2;
                if(s[j]=='1') val++;
                if(val==aktlen) res++;
            }
            //if(i==2) cout<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}