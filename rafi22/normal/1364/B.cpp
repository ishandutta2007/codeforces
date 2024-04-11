#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int tab[n+7];
        for(int i=1;i<=n;i++) cin>>tab[i];
        int mx=n,mn=1;
        vector <int> ans;
        ans.push_back(tab[1]);
        ans.push_back(tab[2]);
        for(int i=3;i<=n;i++)
        {
            if(ans[ans.size()-2]<ans[ans.size()-1]&&ans[ans.size()-1]<tab[i])
            {
                ans.pop_back();
                ans.push_back(tab[i]);
            }
            else if(ans[ans.size()-2]>ans[ans.size()-1]&&ans[ans.size()-1]>tab[i])
            {
                ans.pop_back();
                ans.push_back(tab[i]);
            }
            else ans.push_back(tab[i]);
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}