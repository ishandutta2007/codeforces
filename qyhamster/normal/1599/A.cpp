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

const ll inf = 1LL<<60;
int n;
ll a[200010];
string s;
ll mov[200010], lim[200010];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n) cin >> a[i];
    sort(a, a+n);
    cin >> s;
    int cur = n-1;
    for(int i=s.size()-1; i>=1; i--)
    {
        if(s[i] == 'L' && s[i-1] == 'R') mov[i] = -a[cur--];
        else if(s[i] == 'R' && s[i-1] == 'L') mov[i] = a[cur--];
    }
    if(s[s.size()-1] == 'L') mov[n] = inf;
    else mov[n] = -inf;
    ll lastmov = mov[n];
    for(int i=n-1; i>=0; i--)
    {
        if(mov[i]) lastmov = mov[i];
        lim[i] = -lastmov;
    }
    /*forn(i, n)
    {
        cout << mov[i] << " ";
    }
    cout << endl;
    forn(i, n)
    {
        cout << lim[i] << " ";
    }
    cout << endl;*/
    ll pos = 0;
    forn(i, n)
    {
        if(!mov[i])
        {
            //cout << i << " " << pos << " " << lim[i] << endl;
            if(pos > lim[i])
            {
                if(pos - a[cur] > lim[i])
                {
                    mov[i] = -a[cur];
                }
                else mov[i] = a[cur];
            }
            else
            {
                if(pos + a[cur] < lim[i])
                {
                    mov[i] = a[cur];
                }
                else mov[i] = -a[cur];
            }
            pos += mov[i];
            cur--;
        }
        else pos += mov[i];
    }
    forn(i, n)
    {
        if(mov[i] > 0) cout << mov[i] << " R" << '\n';
        else cout << -mov[i] << " L" << '\n';
    }
}