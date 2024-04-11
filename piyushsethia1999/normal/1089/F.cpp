#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define m_p make_pair
#define inf 200000000000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c) {string tem(1, c); return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first

/////////////

int ansn[20], ansd[20];
int si=0;
int a[21];
int K = 0;
bool recur(int i, int v, int tar)
{
    if(v==tar)
    return 1;
    if (i == K)
    {
        if (v == tar)
            return true;
        return false;
    }
    int j = 0;
    while (v + j * a[i] <= tar)
    {
        if (recur(i + 1, v + j * a[i], tar))
        {
            ansn[si++]=(j);
            ansd[si-1]=(tar+1)/a[i];
            return true;
        }
        ++j;
    }
    return false;
}

signed main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
    }
    if (v.size() == 0)
    {
        cout << "NO";
    }
    else
    {
        sort(v.begin(), v.end());
        int ch[v.size()] = {};
        for (int i = 0; i < v.size(); ++i)
        {
            if (ch[i] == 0)
                for (int j = i + 1; j < v.size(); ++j)
                    if (v[j] % v[i] == 0)
                        ch[j] = 1;
        }
        for (int i = 0; i < v.size(); ++i)
            if (ch[i] == 0) {
                a[K++] = v[i];
            }
        if (K <= 1)
        {
            cout << "NO";
            return 0;
        }
        --n;
        recur(0, 0, n);
        if (si == 0)
        {
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        int c = 0;
        for (int j=0;j<si;++j)
        {
            int r=ansn[j];
            if (r == 0)
                ++c;
        }
        cout << si - c << "\n";
        for (int i = 0; i < si; ++i)
        {
            if (ansn[i] != 0)
                cout << ansn[i] << " " << ansd[i] << "\n";
        }
    }
}