#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long int,long long int>

using namespace std;

int n;

const int nax = 1e6 + 5;
string s[nax];
vector<int> dp[nax];
vector<int> ord[nax];
vector<int> nxt_dif;

const int modd = 1e9 + 7;

ll p[nax][2];
ll odw[2];
int mod[2];
vector<pii> hasz[nax];

void policz_hasze()
{
    for(int i=1;i<=n;i++)
    {
        int k = s[i].size();
        hasz[i].resize(k);
        for(int j=0;j<k;j++)
        {
            ll akt1 = p[j][0] * (s[i][j] - 'a' + 1);
            akt1 %= mod[0];
            ll akt2 = p[j][1] * (s[i][j] - 'a' + 1);
            akt2 %= mod[1];
            pll pop = mp(0,0);
            if(j) pop = hasz[i][j-1];
            pop.st += akt1;
            pop.nd += akt2;
            pop.st %= mod[0];
            pop.nd %= mod[1];
            hasz[i][j] = pop;
        }
    }
}

pii dawaj_hasza(int idx,int len,int bez)
{
    if(len == 0) return mp(0,0);
    if(bez >= len) return hasz[idx][len - 1];
    len++;

    pll ans = mp(0,0);
    if(bez) ans = hasz[idx][bez - 1];
    int lo = bez + 1;
    int hi = len - 1;
    pll dodaj = hasz[idx][hi];
    pll zabierz = hasz[idx][lo - 1];
    dodaj.st -= zabierz.st;
    dodaj.nd -= zabierz.nd;
    if(dodaj.st < 0) dodaj.st += mod[0];
    if(dodaj.nd < 0) dodaj.nd += mod[1];

    dodaj.st *= odw[0];
    dodaj.st %= mod[0];
    dodaj.nd *= odw[1];
    dodaj.nd %= mod[1];

    ans.st += dodaj.st;
    ans.nd += dodaj.nd;
    if(ans.st >= mod[0]) ans.st -= mod[0];
    if(ans.nd >= mod[1]) ans.nd -= mod[1];

    return ans;

}

void pre()
{
    p[0][0] = 1;
    p[0][1] = 1;
    p[1][0] = 29;
    p[1][1] = 31;
    mod[0] = 1e9 + 7;
    mod[1] = 1e9 + 9;
    for(int i=2;i<nax;i++)
    {
        for(int j=0;j<2;j++)
        {
            p[i][j] = p[i-1][j] * p[1][j];
            p[i][j] %= mod[j];
        }
    }
    odw[0] = 758620695;
    odw[1] = 838709685;
    policz_hasze();
}


void calc_nxt_dif(int idx)
{
    int k = s[idx].size();
    nxt_dif.resize(k);
    nxt_dif[k - 1] = 1e9;
    for(int i=k-2;i>=0;i--)
    {
        if(s[idx][i] == s[idx][i+1]) nxt_dif[i] = nxt_dif[i + 1];
        else nxt_dif[i] = i + 1;
    }
}

int cur;

bool cmp(int x,int y)
{
    bool rev = false;
    if(y < x)
    {
        swap(x,y);
        rev = true;
    }
    int nast = nxt_dif[x];
    if(nast > y)
    {
        if(rev) swap(x,y);
        return x < y;
    }

    char akt = s[cur][x];
    char nowa = s[cur][nast];

    bool mniejszy = (nowa < akt);
    if(rev) mniejszy = !mniejszy;
    return mniejszy;
}

bool rowno(int idx1,int len1,int bez1,int idx2,int len2,int bez2)
{
    return dawaj_hasza(idx1,len1,bez1) == dawaj_hasza(idx2,len2,bez2);
}

void calc_ord(int idx)
{
    bool ok = (idx == 2);
    int k = s[idx].size();
    ord[idx].resize(k);
    for(int j=0;j<k;j++) ord[idx][j] = j;
    sort(ord[idx].begin(),ord[idx].end(),cmp);
    vector<int> wynik;
    bool done = false;
    for(int i=0;i<k;i++)
    {
        int akt = ord[idx][i];
        int lo = 0;
        int hi = k - 1;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(rowno(idx,mid,akt,idx,mid,k)) lo = mid;
            else hi = mid;
        }
        int ile = lo;
        if(rowno(idx,hi,akt,idx,hi,k)) ile = hi;
        if(ile == k - 1)
        {
            wynik.pb(akt);
            continue;
        }
        char calego = s[idx][ile];
        char mam = s[idx][ile];
        if(akt <= ile) ile++;
        mam = s[idx][ile];
        if(mam <= calego)
        {
            wynik.pb(akt);
            continue;
        }
        else
        {
            done = true;
            wynik.pb(k);
            break;
        }
    }
    if(!done) wynik.pb(k);
    else
    {
        for(int i=wynik.size()-1;i<k;i++) wynik.pb(ord[idx][i]);
    }
    ord[idx] = wynik;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    pre();
    cur = 1;
    int k = s[1].size();
    dp[1].resize(k + 1);
    calc_nxt_dif(1);
    calc_ord(1);
    for(int i=0;i<=k;i++) dp[1][i] = 1;
    for(int i=2;i<=n;i++)
    {
        cur = i;
        int k = s[i].size();
        dp[i].resize(k + 1);
        calc_nxt_dif(i);
        calc_ord(i);
        int smaller_cnt = 0;
        int ans = 0;
        for(int j=0;j<=k;j++)
        {
            int akt = ord[i][j];
            while(smaller_cnt + 1 <= ord[i - 1].size())
            {
                int pop = ord[i-1][smaller_cnt];
                int lo = 0;
                int len1 = k - 1 + (akt == k);
                int len2 = (int)s[i-1].size() - 1 + (pop == s[i-1].size());
                int hi = min(len1,len2);
                while(lo + 1 < hi)
                {
                    int mid = (lo + hi) / 2;
                    if(rowno(i,mid,akt,i-1,mid,pop)) lo = mid;
                    else hi = mid;
                }
                int eq = lo;
                if(rowno(i,hi,akt,i-1,hi,pop)) eq = hi;

                if(eq == min(len1,len2))
                {
                    if(eq == len1 && eq == len2)
                    {
                        ans += dp[i-1][smaller_cnt];
                        smaller_cnt++;
                        if(ans >= modd) ans -= modd;
                        continue;
                    }
                    else if(eq == len1)
                    {
                        break;
                    }
                    else
                    {
                        ans += dp[i-1][smaller_cnt];
                        smaller_cnt++;
                        if(ans >= modd) ans -= modd;
                        continue;
                    }
                }

                char teraz = s[i][eq + (akt <= eq)];
                char poprzedni = s[i-1][eq + (pop <= eq)];

                if(teraz >= poprzedni)
                {
                    ans += dp[i-1][smaller_cnt];
                    smaller_cnt++;
                    if(ans >= modd) ans -= modd;
                    continue;
                }
                else break;
            }
            dp[i][j] = ans;
        }
    }

    int ans = 0;
    k = s[n].size();
    for(int i=0;i<=k;i++)
    {
        ans += dp[n][i];
        if(ans >= modd) ans -= modd;
    }
    cout<<ans<<endl;

    return 0;
}