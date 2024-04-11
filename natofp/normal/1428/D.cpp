#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 1e5 + 5;

int a[nax];

vector<pii> ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int last = n;
    set<pii> wolne1;
    set<pii> wolne23;
    for(int i=n;i>=1;i--)
    {
        if(a[i] == 0) continue;
        if(a[i] == 1)
        {
            ans.pb(mp(i,last));
            wolne1.insert(mp(i,last));
            last--;
            continue;
        }
        if(a[i] == 2)
        {
            if(wolne1.size() == 0)
            {
                cout<<-1<<"\n";
                return 0;
            }
            pii akt = *wolne1.begin();
            wolne1.erase(wolne1.find(akt));
            ans.pb(mp(i,akt.nd));
            wolne23.insert(mp(i,akt.nd));
            continue;
        }
        if(a[i] == 3)
        {
            if(wolne23.size() + wolne1.size() == 0)
            {
                cout<<-1<<"\n";
                return 0;
            }

            if(wolne23.size())
            {
                pii akt = *wolne23.begin();
                wolne23.erase(akt);
                ans.pb(mp(i,last));
                ans.pb(mp(akt.st,last));
                wolne23.insert(mp(i,last));
                last--;
            }
            else
            {
                pii akt = *wolne1.begin();
                wolne1.erase(akt);
                ans.pb(mp(i,last));
                ans.pb(mp(akt.st,last));
                wolne23.insert(mp(i,last));
                last--;
            }

        }
    }
    cout<<ans.size()<<"\n";
    for(auto akt : ans)
    {
        cout<<akt.nd<<" "<<akt.st<<"\n";
    }


    return 0;
}