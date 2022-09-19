#include <bits/stdc++.h>

using namespace std;
int n;
int t[100001];
int s[100001];
bool k[100001];
int w=0;
vector<int> m;
vector<int> mm;
map <int, int> p;
void rendezes(int a)
{
    k[a]=true;
    m.push_back(a);
    if (!k[p[t[a]]]) {
        rendezes(p[t[a]]);
    } else {
        sort(m.begin(), m.end());
        w++;
        mm.push_back(m.size());
        for (int i=0; i<m.size(); i++) {
            mm.push_back(m[i]);
        }
        mm.push_back(0);
        m.clear();
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s[i]=t[i];
    }
    sort(s+1, s+n+1);
    for (int i=1; i<=n; i++) {
        p[s[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        if (k[i]==false) {
            rendezes(i);
        }
    }
    cout << w << endl;
    for (int i=0; i<mm.size(); i++) {
        if (mm[i]==0) {
            cout << endl;
        } else {
            cout << mm[i] << " ";
        }
    }
    return 0;
}