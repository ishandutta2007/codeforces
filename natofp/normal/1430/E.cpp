#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

vector<int> pos[26];
const int nax = 2e5 + 5;
char s[nax];

const int roz = (1<<19);
int tree[roz];

void wstaw(int pos,int val)
{
    pos += roz/2;
    while(pos >= 1)
    {
        tree[pos] += val;
        pos /= 2;
    }
}

int ask(int lo,int hi,int u,int a,int b)
{
    if(lo == a && b == hi) return tree[u];
    if(b<=a) return 0;
    int mid = (lo+hi) / 2;
    int l = ask(lo,mid,u*2,a,min(b,mid));
    int r = ask(mid,hi,u*2+1,max(a,mid),b);
    return l + r;
}

int done[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string x; cin>>x;
    for(int i=1;i<=n;i++) s[i] = x[i-1];
    for(int i=1;i<=n;i++)
    {
        pos[s[i]-'a'].pb(i);
    }
    ll ans = 0;
    for(int i=n;i>=1;i--)
    {
        char akt = s[i];
        int poz = pos[akt - 'a'][done[akt - 'a']] + ask(0,roz/2,1,pos[akt - 'a'][done[akt - 'a']],n+1);
        int dest = n - i + 1;
        done[akt - 'a']++;

        int len = poz - dest;

        ans += len;
        wstaw(pos[akt-'a'][done[akt-'a'] - 1] ,1);

    }
    cout<<ans;


    return 0;
}