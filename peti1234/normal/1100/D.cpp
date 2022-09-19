#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > v;
int t[1001][1001];
int n=999, m=999;
int x, y;
int e, f;
int main()
{
    cin >> x >> y;
    v.push_back({0, 0});
    for (int i=1; i<=666; i++) {
        int c, d;
        cin >> c >> d;
        v.push_back({c, d});
    }
    e=500, f=500;
    while(x!=e) {
        int p=e-x;
        if (p>0) {
            p=1;
        } else {
            p=-1;
        }
        cout.flush() << x+p << " " << y << endl;
        x+=p;
        int a, b, c;
        cin >> a >> b >> c;
        if (a==-1) {
            return 0;
        }
        v[a].first=b;
        v[a].second=c;
    }

    while(y!=f) {
        int p=f-y;
        if (p>0) {
            p=1;
        } else {
            p=-1;
        }
        cout.flush() << x << " " << y+p << endl;
        y+=p;
        int a, b, c;
        cin >> a >> b >> c;
        if (a==-1) {
            return 0;
        }
        v[a].first=b;
        v[a].second=c;
    }
    int kk=0, kn=0, nk=0, nn=0;
    for (int i=1; i<=666; i++) {
        int fi=v[i].first;
        int se=v[i].second;
        t[fi][se]++;
        if (fi<e) {
            if (se<f) {
                kk++;
            } else {
                kn++;
            }
        } else {
            if (se<f) {
                nk++;
            } else {
                nn++;
            }
        }
    }
    int aa=0, bb=0;
    if (kk<=166) {
        aa=1, bb=1;
    }
    if (kn<=166) {
        aa=1, bb=-1;
    }
    if (nk<=166) {
        aa=-1, bb=1;
    }
    if (nn<=166) {
        aa=-1, bb=-1;
    }
    while(true) {
        if (x+aa>0 && x+aa<=n) {
            x+=aa;
        }
        if (y+bb>0 && y+bb<=n && t[x][y+bb]==0) {
            y+=bb;
        }
        cout.flush() << x << " " << y << endl;
        int a, b, c;
        cin >> a >> b >> c;
        if (a==-1) {
            break;
        }
        t[v[a].first][v[a].second]--;
        t[b][c]++;
        v[a].first=b;
        v[a].second=c;
    }

    return 0;
}