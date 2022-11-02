#include <bits/stdc++.h>

using namespace std;
int pref[200007];
bool is[200007];

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n;
        int tab[n+3];
        int pos[n+3];
        int r[n+3];
        int maxi=1;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++) r[i]=1;
        multiset <int> maxim;
        set <int> poses;
        for(int i=1;i<=n;i++)
        {
            maxim.insert(1);
            poses.insert(i);
        }
        for(int i=1;i<=n;i++) pos[tab[i]]=i;
        bool b=1;
        for(int i=1;i<=n;i++)
        {
            if(r[pos[i]]!=maxi) b=0;
            maxim.erase(maxim.find(r[pos[i]]));
            poses.erase(pos[i]);

            set <int>::iterator it;
            it=poses.upper_bound(pos[i]);
            if(it!=poses.end())
            {
                maxim.insert(r[pos[i]]+r[*it]);
                r[*it]+=r[pos[i]];
            }
             r[pos[i]]=0;
            if(maxim.size()>0)
                maxi=*--maxim.end();
        }
        if(b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


    }
    return 0;
}