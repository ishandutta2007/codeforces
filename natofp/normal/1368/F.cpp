#include <bits/stdc++.h>
#define ll long long int
#define pb push_back


using namespace std;

int stan[1111];

int ok[1111];

void ans()
{
    cout<<0<<endl;
    fflush(stdout);
    exit(0);
}
int n;
int ile = 0;

void ask(vector<int> a)
{
    cout<<a.size()<<" ";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i];
        if(i<a.size()-1) cout<<" ";
        if(stan[a[i]] == 0)
        {
            stan[a[i]] = 1;
            ile++;
        }
    }
    cout<<endl;
    fflush(stdout);
    int x; cin>>x;
    int roz = a.size();
    for(int i=0;i<roz;i++)
    {
        int pos = x+i;
        if(pos>n) pos -= n;
        if(stan[pos]==1)
        {
            stan[pos] = 0;
            ile--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    //if(n<=3) ans();
    int opt = -1;
    int res = 111111;
    for(int i=1;i<=n;i++)
    {
        int rozgr = i;
        int zera = 0;
        for(int j=1;j<=n;j++)
        {
            if(j%(rozgr+1)==0) zera++;
            else if(j==n) zera++;
        }
        if(zera+rozgr<res)
        {
            opt = i;
            res = zera + rozgr;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%(opt+1)!=0 && i!=n) ok[i] = true;
    }
    while(ile<n-res)
    {
        vector<int> pyt;
        pyt.clear();
        for(int i=1;i<=n;i++)
        {
            if(ok[i]==true && stan[i]==false) pyt.pb(i);
        }
        ask(pyt);
    }
    ans();
    return 0;
}