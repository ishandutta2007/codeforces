#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>ans(n+1);
        string s;
        cin>>s;
        map<int,int>cnt;
        for(auto x:s)
            cnt[x-'a']++;
        int t=k;
        for(int i=0;i<26;i++)
        {
            t=min(t,cnt[i]);
            for(int j=1;j<=t;j++)
                ans[j]++;
        }
        for(int i=1;i<=k;i++)
            cout<<(char)(min(n/k,ans[i])+'a');
        cout<<"\n";
    }
}