#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, res[c], fel[c], maxi;
bool v[c];
vector<int> sz[c];
string pot[c];

void dfs(int a, int el) {
    fel[a]=el;
    for (int x:sz[a]) {
        if (x!=el) {
            dfs(x, a);
        }
    }
    string s, ss;
    for (int i=0; i<n; i++) {
        s+='1';
    }
    ss=s;
    for (int i=0; i<n; i++) {
        s[i]='0';
        ss=s;
        bool baj=0;
        priority_queue<string> q1;
        for (int x:sz[a]) {
            if (x!=el) {
                q1.push(pot[x]);
            }
        }
        bool spec=0;
        for (int j=0; j<n; j++) {
            if (q1.size()==0) {
                break;
            }
            if (s[j]=='1') {
                string p=q1.top();
                q1.pop();
                if (p[j]=='1') {
                    p[j]='0';
                    q1.push(p);
                }
                if (p>ss) {
                    baj=1;
                }
            }
            ss[j]='0';
        }
        if (q1.size()>0) {
            baj=1;
        }
        if (baj) {
            s[i]='1';
        }
    }
    pot[a]=s;
    priority_queue<pair<string, int> > q2;
    for (int x:sz[a]) {
        if (x!=el) {
            q2.push({pot[x], x});
        }
    }
    for (int i=0; i<n; i++) {
        if (q2.size()==0) {
            break;
        }
        if (s[i]=='1') {
            auto ut=q2.top();
            q2.pop();
            if (ut.first[i]=='1') {
                ut.first[i]='0';
                q2.push(ut);
            } else {
                res[ut.second]=i;
            }
        }
    }
}
void torol(int a, int b) {
    v[a]=true;
    for (int x:sz[a]) {
        if (x!=b) {
            torol(x, a);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1, 0);
    while (true) {
        int mini=0;
        for (int i=2; i<=n; i++) {
            if (!v[i] && !v[fel[i]]) {
                if (mini==0 || res[i]<res[mini]) {
                    mini=i;
                }
            }
        }
        if (!mini) {
            break;
        }
        cout.flush() << "? " << mini << " " << fel[mini] << endl;
        int ans;
        cin >> ans;
        torol(mini+fel[mini]-ans, ans);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cout.flush() << "! " << i << endl;
        }
    }
    return 0;
}