#include <bits/stdc++.h>
#define ll long long int

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m; cin>>n>>m;
    ll ile=0;
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        ile+=((i-1)/2);
        if(ile>=m)
        {
            idx=i;
            break;
        }
    }
    if(m==0)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<100000000+i<<" ";
        }
        return 0;
    }
    if(idx==0)
    {
        cout<<-1; return 0;
    }

    //cout<<idx<<endl;
    //cout<<"XD"<<endl;
    vector<int> ans;
    for(int i=1;i<=idx-1;i++)
    {
        ans.push_back(i);
    }
    ile-=(idx-1)/2;
    ll trzeba=m-ile;
    ans.push_back(ans.back()+(int)ans.size()-2*trzeba+1);
    int kurwa=ans.size();
    for(int i=0;i<n-kurwa;i++)
    {
        ans.push_back(100000000+i*10050);
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}