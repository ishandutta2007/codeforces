#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,k;
        cin>>n>>k;
        vector <int> dzielniki;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                dzielniki.push_back(i);
                dzielniki.push_back(n/i);
            }
        }
        sort(dzielniki.begin(),dzielniki.end(),greater<int>());
        for(int i=0;i<dzielniki.size();i++)
        {
            if(dzielniki[i]<=k)
            {
                cout<<n/dzielniki[i]<<endl;
                break;
            }
        }

    }
    return 0;
}