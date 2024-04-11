#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > res;
    for(int i=0;i<n+1;i++)
    {
        res.push_back(make_pair(i,i));
        res.push_back(make_pair(i+1,i));
        res.push_back(make_pair(i,i+1));
    }
    res.push_back(make_pair(n+1,n+1));
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}