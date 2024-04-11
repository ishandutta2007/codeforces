#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

void ff()
{
    fflush(stdout);
}

const int nax = 1e6 + 5;
int gdzie[nax];

int nxt[nax];

vector<int> parki[nax];


bool vis[nax];

vector<vector<int> > cycle;
vector<int> tmp;

int n;

void dfs(int m)
{
    tmp.pb(gdzie[m]);
    int x = m;
    if(x > n) x -= n;
    vis[x] = true;
    int nast = m + n;
    if(nast > 2 * n) nast = m - n;
    int serio;
    for(int y : parki[gdzie[nast]])
    {
        if(y != nast) serio = y;
    }
    int w = serio;
    if(w > n) w -= n;
    if(vis[w] == false) dfs(serio);
}

bool done[nax];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n;

    if(n % 2 == 0)
    {
        cout<<"First"<<endl;
        for(int i=1;i<=2*n;i++)
        {
            int akt = i;
            if(akt > n) akt -= n;
            cout<<akt<<" ";
        }
        cout<<endl;
        ff();
        int x; cin>>x;
        return 0;
    }

    cout<<"Second"<<endl;
    ff();
    for(int i=1;i<=2*n;i++)
    {
        cin>>gdzie[i];
    }


    for(int i=1;i<=2*n;i++)
    {
        int akt = gdzie[i];
        parki[akt].pb(i);
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i] == true) continue;
        tmp.clear();
        dfs(i);
        cycle.pb(tmp);
    }
    vector<int> ans;
    int idx;
    for(int i=0;i<cycle.size();i++)
    {
        if(cycle[i].size() % 2 == 1) idx = i;
    }
    swap(cycle[idx],cycle[cycle.size()-1]);
    ll sum = 0;
    for(int i=0;i<cycle.size() -1;i++)
    {
        vector<int> akt= cycle[i];
        for(int j=0;j<akt.size();j++)
        {
            int para = akt[j];
            int one = parki[para][0];
            int dwa = parki[para][1];
            int w = one;
            if(w > n) w -= n;
            if(done[w] == false)
            {
                sum += one;
                ans.pb(one);
                done[w] = true;
            }
            else
            {
                sum += dwa;
                ans.pb(dwa);
                int z = dwa;
                if(z > n) z -= n;
                done[z] = true;
            }
        }
    }
    vector<int> akt = cycle.back();
    ll pot = 0;
    set<int> ans2;
    ans2.clear();
    for(int j=0;j<akt.size();j++)
    {
        int para = akt[j];
        int one = parki[para][0];
        int dwa = parki[para][1];
        int w = one;
            if(w > n) w -= n;
            if(done[w] == false)
            {
                pot += one;
                ans2.insert(one);
                done[w] = true;
            }
            else
            {
                pot += dwa;
                ans2.insert(dwa);
                int z = dwa;
                if(z > n) z -= n;
                done[z] = true;
            }
    }
    set<int> ans3;
    ans3.clear();
    for(int j=0;j<akt.size();j++)
    {
        int para = akt[j];
        int one = parki[para][0];
        int dwa = parki[para][1];
        int w = one;
        if(ans2.count(one)) ans3.insert(dwa);
        else ans3.insert(one);
    }
    if((pot + sum) % (2 * n) != 0)
    {
        ans2 = ans3;
    }
    for(int x : ans) cout<<x<<" ";
    for(int x : ans2) cout<<x<<" ";
    cout<<endl;
    ff();
    return 0;
}