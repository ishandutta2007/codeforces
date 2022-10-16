#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n,k;
const int nax=2e5+5;
int a[nax];
int b[nax];

int ile[nax];
int cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> jd;
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        ile[a[i]]++;
        ile[b[i]]++;
        cnt++;
        if(ile[b[i]]==2) cnt--;
        if(a[i]!=b[i] && ile[a[i]]==2) cnt--;
        if(cnt==0)
        {
            jd.push_back(i);
        }
    }
    if(jd.size()<k) cout<<"NO";
    else
    {
        vector<char> res;
        res.resize(n+1);
        int wsk=0;
        int akt=1;
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            res[a[i]]=(char('a'-1+min(akt,k)));
            if(jd[wsk]==i) {akt++; wsk++;}
        }
        for(int i=1;i<=n;i++)
        {
            cout<<res[i];
        }
    }
    return 0;
}