#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define ull unsigned long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define forn(i, n) for(int i=0; i<int(n); i++)
#define Forn(i, n) for(int i=1; i<=int(n); i++)

using namespace std;

int n, k;
int b[1010], done[1010], a[1010];

vector<pii> od, ev;

unordered_map<int, int> rec[14];
//int rec[12000100][13];
const int max_siz = 13;
int mask1, mask2;
bool found;
//int cnt;

int mask, sum, siz;
void dfs(int x)
{
    if(siz>max_siz) return;
    if(found) return;
    if(x == k)
    {
        //cnt++;
        //cout << "mask = " << mask << ", siz = " << siz << endl;
        if(!siz) return;
        if(rec[siz].count(sum))
        {
            mask1 = rec[siz][sum];
            mask2 = mask;
            found = 1;
            return;
        }
        else rec[siz][sum] = mask;
        return;
    }
    mask += (1<<x);
    sum += b[x];
    siz++;
    dfs(x+1);
    mask -= (1<<x);
    sum -= b[x];
    siz--;
    dfs(x+1);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) cin >> b[i];
    srand(7122);
    random_shuffle(b, b+n);

    forn(i, n)
    {
        if(b[i]&1) od.pb(mp(b[i], i));
        else ev.pb(mp(b[i], i));
    }
    //sort(b, b+n);

    if(n == 2)
    {
        if(b[0] == b[1])
        {
            cout << "YES" << '\n';
            cout << 0 << " " << b[0] << '\n';
        }
        else cout << "NO" << '\n';
        return 0;
    }
    if(n == 3)
    {
        if(b[0] == b[1])
        {
            cout << "YES" << '\n';
            cout << 0 << " " << b[0] << " " << b[2]-b[0] << '\n';
        }
        else if(b[1] == b[2])
        {
            cout << "YES" << '\n';
            cout << 0 << " " << b[1] << " " << b[0]-b[1] << '\n';
        }
        else if(b[0] == b[2])
        {
            cout << "YES" << '\n';
            cout << 0 << " " << b[0] << " " << b[1]-b[0] << '\n';
        }
        else if((b[0]+b[1]+b[2])%2 == 0)
        {
            cout << "YES" << '\n';
            cout << (-b[0]+b[1]+b[2])/2 << " " << (b[0]-b[1]+b[2])/2 << " " << (b[0]+b[1]-b[2])/2 << '\n';
        }
        else cout << "NO" << '\n';
        return 0;
    }
    if(ev.size()>=3)
    {
        cout << "YES" << '\n';
        a[0] = (-ev[0].F+ev[1].F+ev[2].F)/2;
        a[1] = (ev[0].F-ev[1].F+ev[2].F)/2;
        a[2] = (ev[0].F+ev[1].F-ev[2].F)/2;
        done[ev[0].S] = 1;
        done[ev[1].S] = 1;
        done[ev[2].S] = 1;
        //forn(i, n) cout << done[i] << " ";
        //cout << endl;
        int cur = 3;
        forn(i, n)
        {
            if(!done[i])
            {
                //cout << "i = " << i << " " << b[i] << " " << a[0] << endl;
                a[cur++] = b[i] - a[0];
            }
        }
        forn(i, n) cout << a[i] << " ";
        cout << '\n';
        return 0;
    }
    if(ev.size()>=1 && od.size()>=2)
    {
        cout << "YES" << '\n';
        a[0] = (-od[0].F+od[1].F+ev[0].F)/2;
        a[1] = (od[0].F-od[1].F+ev[0].F)/2;
        a[2] = (od[0].F+od[1].F-ev[0].F)/2;
        done[od[0].S] = 1;
        done[od[1].S] = 1;
        done[ev[0].S] = 1;
        int cur = 3;
        forn(i, n)
        {
            if(!done[i]) a[cur++] = b[i] - a[0];
        }
        forn(i, n) cout << a[i] << " ";
        cout << '\n';
        return 0;
    }

    k = min(n, 27);
    dfs(0);
    if(!found)
    {
        cout << "NO" << '\n';
        return 0;
    }
    forn(i, k)
    {
        if((mask1 & (1<<i)) == (1<<i) && (mask2 & (1<<i)) == (1<<i))
        {
            mask1 -= (1<<i);
            mask2 -= (1<<i);
        }
    }
    vector<int> v1, v2, v;
    forn(i, k)
    {
        if((mask1 & (1<<i)) == (1<<i))
        {
            mask1 -= (1<<i);
            v1.pb(i);
            done[i] = 1;
        }
        if((mask2 & (1<<i)) == (1<<i))
        {
            mask2 -= (1<<i);
            v2.pb(i);
            done[i] = 1;
        }
    }
    forn(i, v1.size())
    {
        v.pb(v1[i]);
        if(i!=v1.size()-1) v.pb(v2[i]);
    }

    /*cout << "v: ";
    forn(i, v.size()) cout << v[i] << " ";
    cout << endl;*/

    cout << "YES" << '\n';
    a[0] = 0;
    forn(i, v.size()) a[i+1] = b[v[i]] - a[i];

    int cur = v.size()+1;
    forn(i, n)
    {
        if(!done[i]) a[cur++] = b[i] - a[0];
    }
    forn(i, n) cout << a[i] << " ";
    cout << '\n';
    //cout << "cnt = " << cnt << endl;
}