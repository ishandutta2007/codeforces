#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    vector<int> a;
    vector<int> ans;
    int q; cin>>q;
    while(q--)
    {
        ans.clear();
        int n,k; cin>>n>>k;
        a.resize(n);
        for(int i=0;i<n;i++) cin>>a[i];
        ll sum=0;
        for(int i=0;i<n;i++) sum+=a[i];
        if(sum%2!=k%2)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            ll akt=0;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                akt+=a[i];
                if(cnt<k-1 && akt%2==1)
                {
                    cnt++; akt=0;
                    ans.push_back(i+1);
                }
            }
            ans.push_back(n);
            if(ans.size()<k)
            {
                cout<<"NO"<<"\n";
            }
            else
            {
                cout<<"YES"<<"\n";
                for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}