#include <bits/stdc++.h>

using namespace std;
int n;
int t[200001];
int o[200001];
int s[200001];
bool v[200001];
int apa[200001];
vector<int> sz[200001];
vector<int> l[200001];
void melysegi(int a)
{
    ios_base::sync_with_stdio(false);
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (v[x]) {
            //cout << apa[a] << " ";
            apa[a]=x;
            //cout << x << " "  << apa[a] << endl;
        } else {
            melysegi(x);
        }
    }
}
int gcd(int a, int b)
{
    while (min(a, b)>0) {
        if (b>a) {
            swap(a, b);
        }
        a%=b;
    }
    return max(a, b);
}
void mennyi(int a)
{
    if (o[apa[a]]==0) {
        mennyi(apa[a]);
    }
    l[a].push_back(s[apa[a]]);
    s[a]=gcd(s[apa[a]], t[a]);
    int x=s[apa[a]];
    x=max(x, gcd(o[apa[a]], t[a]));
    for (int i=0; i<l[apa[a]].size(); i++) {
        if (gcd(t[a], l[apa[a]][i])>s[a] && gcd(t[a], l[apa[a]][i])!=l[a].back()) {
            l[a].push_back(gcd(t[a], l[apa[a]][i]));
        }
        x=max(x, gcd(t[a], l[apa[a]][i]));
    }
    o[a]=x;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    melysegi(1);
    o[1]=t[1];
    s[1]=t[1];
    l[1].push_back(0);
    for (int i=2; i<=n; i++) {
        if (o[i]==0) {
            mennyi(i);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << o[i] << " ";
    }
    //cout << gcd(6, 4) << " " << gcd(13, 21) << " " << gcd(9, 9) << endl;
    return 0;
}