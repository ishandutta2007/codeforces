#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e6+5;
int a[nax];
bool czy[nax];
int akt[nax];
int n;
int cnt=0;
int len=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> xd;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        len++;
        if(a[i]>0)
        {
            if(czy[a[i]]==true)
            {
                cout<<-1; return 0;
            }
            akt[a[i]]++;
            czy[a[i]]=true;
            xd.push_back(a[i]);
        }
        else
        {
            akt[-a[i]]--;
        }
        if(akt[abs(a[i])]<0 || akt[abs(a[i])]>1)
        {
            cout<<-1; return 0;
        }
        if(akt[abs(a[i])]==0) cnt--;
        else cnt++;
        if(cnt==0)
        {
            ans.push_back(len);
            len=0;
            for(int j=0;j<xd.size();j++) czy[xd[j]]=false;
            xd.clear();
            continue;
        }

    }
    int sum=0;
    for(int i=0;i<ans.size();i++) sum+=ans[i];
    if(sum!=n)
    {
        cout<<-1; return 0;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}