#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz[41];
bool t[41][41];
bool v[41];
vector<string> q;
bool p[41];
int maxi;
int nem;
int igen;
int c[41];
void ker(int a)
{
    /*if (c[a]==0) {
        c[a]=1;
        igen++;
        maxi=max(maxi, igen);
        vector<int> e;
        for (int i=0; i<sz[a].size(); i++) {
            int x=sz[a][i];
            if (c[x]==0) {
                e.push_back(x);
            }
            c[x]=-1;
        }
        if (a!=n) {
        ker(a+1);
        }
        igen--;
        for (int i=0; i<e.size(); i++) {
            c[e[i]]=0;
        }
    }*/
    bool f=false;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (c[x]==1) {
            f=true;
        }
    }
    if (!f) {
        c[a]=1;
        igen++;
        if (a!=n) {
            ker(a+1);
        }
        maxi=max(maxi, igen);
        igen--;
    }
    c[a]=-1;
    nem++;
    if (n-nem>maxi && a!=n) {
        ker(a+1);
    }
    nem--;
    c[a]=0;
    return;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w >> n;
    for (int i=1; i<=w+1; i++) {
        int x;
        if (i>w) {
            x=1;
        }
        else {
            cin >> x;
        }
        if (x==1) {
            vector<int> pp;
            for (int i=1; i<=n; i++) {
                if (p[i]) {
                    pp.push_back(i);
                }
            }
            for (int i=0; i<pp.size(); i++) {
                for (int j=i+1; j<pp.size(); j++) {
                    t[pp[i]][pp[j]]=true;
                    t[pp[j]][pp[i]]=true;
                }
            }
            pp.clear();
            for (int i=1; i<=40; i++) {
                p[i]=false;
            }
        } else {
            string s;
            cin >> s;
            bool f=false;
            for (int i=0; i<q.size(); i++) {
                if (q[i]==s) {
                    p[i+1]=true;
                    f=true;
                }
            }
            if (!f) {
                q.push_back(s);
                p[q.size()]=true;

            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (t[i][j]) {
                sz[i].push_back(j);
                //cout << i << " " << j << endl;
            }
        }
    }
    ker(1);
    cout << maxi << endl;
    return 0;
}