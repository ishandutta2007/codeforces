#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 55;
int a[nax];
int n;

vector<vector<int> > ans;

bool ok()
{
    for(int i=2;i<=n;i++)
    {
        if(a[i] < a[i-1]) return false;
    }
    return true;
}

int daj(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i] == x) return i;
    }
}

void prt()
{
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void go(vector<int> s)
{
    ans.pb(s);
    vector<vector<int> > akt;
    int done = 0;
    for(int i=1;i<=n;i++)
    {
        int cur = s[done++];
        vector<int> teraz;
        for(int j=i;j<i+cur;j++) teraz.pb(a[j]);
        akt.pb(teraz);
        i += cur - 1;
    }
    reverse(akt.begin(),akt.end());
    done = 0;
    for(vector<int> teraz : akt)
    {
        int sz = teraz.size();
        for(int i=done+1;i<=done+sz;i++)
        {
            a[i] = teraz[i-done-1];
        }

        done += sz;
    }

}

void kon()
{
    cout<<ans.size()<<endl;
    for(auto x : ans)
    {
        cout<<x.size()<<" ";
        for(int y : x) cout<<y<<" ";
        cout<<endl;
    }
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(a[n] != 1)
    {
        int p = daj(1);
        vector<int> akt;
        akt.pb(p);
        akt.pb(n - p);
        go(akt);
    }
    if(n == 1) kon();

    vector<int> akt;
    int p = daj((n+1)/2 + 1);
    akt.pb(p);
    for(int i=1;i<=n-p;i++) akt.pb(1);
    go(akt);

    int sz = (n+1) / 2 + 1;
    int done = 2;
    while(ok() == false)
    {
        if(done < n - 2 || n % 2 == 0)
        {
            int akt = sz + done / 2;
            if(done % 2 == 1)
            {
                akt = done / 2 + 1;
            }
            int pozycja = daj(akt);
            vector<int> kurwa;
            kurwa.pb(done / 2);
            kurwa.pb(n - pozycja + 1 - done / 2);
            kurwa.pb(n - kurwa[0] - kurwa[1] - (done / 2 + done % 2));
            kurwa.pb(n - kurwa[0] - kurwa[1] - kurwa[2]);
            reverse(kurwa.begin(),kurwa.end());
            vector<int> c;
            for(int x : kurwa)
            {
                if(x) c.pb(x);
            }
            kurwa = c;
            go(kurwa);
            done++;
        }
        else
        {
            vector<int> kurwa;
            kurwa.pb(done / 2);
            int nxt = done / 2 + 1;
            if(a[n - done/2] == nxt)
            {
                kurwa.pb(1);
                kurwa.pb(1);
            }
            else kurwa.pb(2);
            kurwa.pb(n - done / 2 - 2);
            reverse(kurwa.begin(),kurwa.end());
            go(kurwa);
        }

    }


    kon();

    return 0;
}