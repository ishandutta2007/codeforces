#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

vector <int> ans;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,p;
    cin>>n>>p;
    int tab[n];
    for(int i=0;i<n;i++) cin>>tab[i];
    sort(tab,tab+n);
    for(int i=1;i<=2000;i++)
    {
        int ok=1;
        int x=i,ile=0,it=0;
        for(int j=0;j<n;j++)
        {
            while(it<n&&tab[it]<=x)
            {
                it++;
                ile++;
            }
           // cout<<j<<" "<<it<<endl;
            if(it==j)
            {
                ok=0;
                break;
            }
            if((it-j)%p==0)
            {
                ok=0;
                break;
            }
            x++;

        }
        if(ok)
        {
            ans.push_back(i);
        }

    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
}