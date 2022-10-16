#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 2e5 + 5;
int a[nax];
int n;

const int XD = 101;

int pref[XD];

vector<int> zapytania[nax];

vector<int> pos[XD];

vector<int> difs[XD][XD];

vector<int> odpy[XD][XD];

int wsk[XD][XD];

void policz(int x,int y)
{
    //cout<<"WA"<<endl;
    bool dbg = (x == 3 && y == 1);
    int done = 0;
    int sz = difs[x][y].size();
    //cout<<"B"<<endl;
   // if(dbg) cout<<"XD"<<endl;
    vector<pii> cur;
    int wsk1 = 0;
    int wsk2 = 0;
    //cout<<"C"<<endl;
    while(cur.size() < pos[x].size() + pos[y].size())
    {
        if(wsk1 == pos[x].size())
        {
            cur.pb(mp(-1,pos[y][wsk2]));
            wsk2++;
        }
        else if(wsk2 == pos[y].size())
        {
            cur.pb(mp(1,pos[x][wsk1]));
            wsk1++;
        }
        else
        {
            if(pos[x][wsk1] <= pos[y][wsk2])
            {
                cur.pb(mp(1,pos[x][wsk1]));
                wsk1++;
            }
            else
            {
                cur.pb(mp(-1,pos[y][wsk2]));
                wsk2++;
            }
        }
    }
    //cout<<"D"<<endl;
    //if(dbg)
   // {
    //    for(pii akt : cur) cout<<akt.st<<" "<<akt.nd<<endl;
   // }

    int bal = 0;

    if(sz && difs[x][y][0] == 0)
    {
        odpy[x][y].pb(0);
        done++;
    }

    //cout<<"E"<<x<<" "<<y<<endl;
   // cout<<"WA"<<endl;
    for(pii akt : cur)
    {
        bal += akt.st;
        //cout<<"WA"<<bal<<endl;
        if(done < sz && difs[x][y][done] == bal)
        {
            odpy[x][y].pb(akt.nd);
            done++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) pos[a[i]].pb(i);

    for(int i=1;i<=n;i++)
    {
        pref[a[i]]++;
        int maxi = 0;
        int id = 0;
        for(int j=1;j<=100;j++)
        {
            if(pref[j] > maxi)
            {
                maxi = pref[j];
                id = j;
            }
        }
        for(int j=1;j<=100;j++)
        {
            if(j == id) continue;
            int dif = pref[id] - pref[j];
            zapytania[dif].pb(id * 105 + j);
        }
    }

    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            difs[i][j].pb(0);
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int z : zapytania[i])
        {
            pii akt;
            akt.nd = z % 105;
            z -= akt.nd;
            akt.st = z / 105;
            if((difs[akt.st][akt.nd].size() > 0 && difs[akt.st][akt.nd].back() != i) || difs[akt.st][akt.nd].size() == 0) difs[akt.st][akt.nd].pb(i);
        }
    }

    for(int i=0;i<nax;i++) zapytania[i].clear();

    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(i != j) policz(i,j);
        }
    }

    for(int j=1;j<=100;j++) pref[j] = 0;

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        pref[a[i]]++;
        int maxi = 0;
        int id = 0;
        for(int j=1;j<=100;j++)
        {
            if(pref[j] > maxi)
            {
                maxi = pref[j];
                id = j;
            }
        }


        //cout<<"****************"<<i<<endl;
        int pepe = 1e9;
        for(int j=1;j<=100;j++)
        {
            if(id == j) continue;

            if(pref[j] == 0) continue;

            int dif = pref[id] - pref[j];

            int ite = wsk[id][j];
            //cout<<"A"<<endl;

            //cout<<"WA"<<"DIF: "<<dif<<"     "<<id<<" "<<j<<" "<<ite<<" "<<difs[id][j].size()<<endl;

            while(difs[id][j][ite] < dif) ite++;
            while(difs[id][j][ite] > dif) ite--;

            //cout<<"BEE"<<ite<<endl;

            wsk[id][j] = ite;
            pepe = min(pepe,odpy[id][j][ite]);

        }

        ans = max(ans,i - pepe);

    }

    cout<<ans;

    return 0;
}