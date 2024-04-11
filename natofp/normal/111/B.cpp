#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int> last(N,-1);

vector<int> znajdz(int x)
{
    vector<int> res;
    for(int i=1;i*i<=x;i++)
    {
        if(i*i==x)
        {
            res.push_back(i);
        }
        else if(x%i==0)
        {
            res.push_back(i);
            res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y; cin>>x>>y;
        vector<int> dzielniki=znajdz(x);
        int res=0;
        for(int j=0;j<dzielniki.size();j++)
        {
            int t=dzielniki[j];
            if(last[t]==-1 || last[t] <i-y) res++;
            last[t]=i;
        }
        cout<<res<<endl;
    }

    return 0;
}