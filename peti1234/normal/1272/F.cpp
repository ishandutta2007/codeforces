#include <bits/stdc++.h>

using namespace std;
const int c=205;
int sx, sy, tav[c][c][c], valt[c][c][c], db;
bool v[c][c][c], ut[c][c][c];
string x, y, ans;
queue<pair<pair<int, int>, int> > q;
void add(int a, int b, int c) {
    q.push({{a, b}, c});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    sx=x.size(), sy=y.size();
    add(0, 0, 0);
    while (q.size()>0) {
        auto s=q.front();
        q.pop();
        int a=s.first.first, b=s.first.second, dif=s.second;
        if (max({a, b, dif})>=c) {
            continue;
        }
        if (dif>0) {
            int aa=a, bb=b;
            int ert=0;
            if (aa<sx && x[aa]==')') {
                aa++;
                ert+=1;
            }
            if (bb<sy && y[bb]==')') {
                bb++;
                ert+=2;
            }
            if (!v[aa][bb][dif-1]) {
                v[aa][bb][dif-1]=1, ut[aa][bb][dif-1]=1, valt[aa][bb][dif-1]=ert;
                tav[aa][bb][dif-1]=tav[a][b][dif]+1;
                add(aa, bb, dif-1);
            }
        }
        int aa=a, bb=b;
        int ert=0;
        if (aa<sx && x[aa]=='(') {
            aa++;
            ert+=1;
        }
        if (bb<sy && y[bb]=='(') {
            bb++;
            ert+=2;
        }
        if (!v[aa][bb][dif+1]) {
            v[aa][bb][dif+1]=1, ut[aa][bb][dif+1]=0, valt[aa][bb][dif+1]=ert;
            tav[aa][bb][dif+1]=tav[a][b][dif]+1;
            add(aa, bb, dif+1);
        }
    }
    int bal=0;
    db=tav[sx][sy][0];
    for (int i=1; i<=db; i++) {
        int ert=valt[sx][sy][bal];
        if (ut[sx][sy][bal]) {
            bal++;
            ans+=')';
        } else {
            bal--;
            ans+='(';
        }
        if (ert & 1) {
            sx--;
        }
        if (ert & 2) {
            sy--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}