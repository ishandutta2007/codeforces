#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int v[c][c], s[c][c];
int a, b, xw, yw, xb, yb;
bool kesz=false;
pair<int, int> sz(int a, int b, int c)
{
    if (c==1) return {a-2, b-1};
    if (c==2) return {a-2, b+1};
    if (c==3) return {a+2, b-1};
    if (c==4) return {a+2, b+1};
    if (c==5) return {a-1, b-2};
    if (c==6) return {a-1, b+2};
    if (c==7) return {a+1, b-2};
    if (c==8) return {a+1, b+2};
}
bool val(int x, int y) {
    return (x>=1 && x<=a && y>=1 && y<=b);
}
void wbfs() {
    queue<pair<pair<int, int>, int> >q;
    q.push({{a/2, b/2}, 1});
    while(q.size()>0) {
        int fi=q.front().first.first;
        int se=q.front().first.second;
        int e=q.front().second;
        q.pop();
        if (val(fi, se) && v[fi][se]==0) {
            v[fi][se]=e;
            for (int i=1; i<=8; i++) {
                int x=sz(fi, se, i).first;
                int y=sz(fi, se, i).second;
                if (!v[x][y]) {
                    q.push({{x, y}, e+1});
                }
            }
        }
    }
}
void bbfs() {
    queue<pair<pair<int, int>, int> >q;
    q.push({{a/2+1, b/2}, 1});
    while(q.size()>0) {
        int fi=q.front().first.first;
        int se=q.front().first.second;
        int e=q.front().second;
        q.pop();
        if (val(fi, se) && !s[fi][se]) {
            s[fi][se]=e;
            for (int i=1; i<=8; i++) {
                int x=sz(fi, se, i).first;
                int y=sz(fi, se, i).second;
                if (!s[x][y]) {
                    q.push({{x, y}, e+1});
                }
            }
        }
    }
}
void vugras(int xw, int yw, int xb, int yb)
{
    int lx=xb, ly=yb;
    while(v[xw][yw]!=1) {
        for (int i=1; i<=8; i++) {
            int x=sz(xw, yw, i).first;
            int y=sz(xw, yw, i).second;
            if (val(x, y) && v[x][y]<v[xw][yw]) {
                xw=x, yw=y;
                cout.flush() << x << " " << y << "\n";
                if (x==lx && y==ly) {
                    kesz=true;
                    return;
                }
                break;
            }
        }
        if (v[xw][yw]!=1) {
            cin >> lx >> ly;
        }
    }
    return;
}
void bugras(int xw, int yw, int xb, int yb)
{
    int lx=xb, ly=yb;
    while(s[xw][yw]!=1) {
        for (int i=1; i<=8; i++) {
            int x=sz(xw, yw, i).first;
            int y=sz(xw, yw, i).second;
            if (val(x, y) && s[x][y]<s[xw][yw]) {
                xw=x, yw=y;
                cout.flush() << x << " " << y << "\n";
                if (x==lx && y==ly) {
                    kesz=true;
                    return;
                }
                break;
            }
        }
        if (s[xw][yw]!=1) {
            cin >> lx >> ly;
        }
    }
    return;
}
int main()
{
    cin >> a >> b >> xw >> yw >> xb >> yb;
    wbfs();
    bbfs();
    int vv=v[xw][yw], vs=s[xw][yw], sv=v[xb][yb], ss=s[xb][yb];

    if (vv<sv && vv<=ss) {
        cout.flush() << "WHITE" << "\n";
        vugras(xw, yw, xb, yb);
        return 0;
    }
    if (ss+1<vs && ss<vv) {
        cout.flush() << "BLACK" << "\n";
        int lx=xb, ly=yb;
        cin >> lx >> ly;
        bugras(xb, yb, lx, ly);
        return 0;
    }
    if ((xw+yw+xb+yb)%2)  {
        cout << "WHITE" << "\n";
        if (v[xw][yw]==2) {
            cout.flush() << a/2 << " " << b/2 << "\n";
            return 0;
        }
        if (s[xw][yw]!=1) {
        bugras(xw, yw, xb, yb);
        if (kesz) {
            return 0;
        }
        cin >> xb >> yb;
        }
        xw=a/2+1, yw=b/2;
        xw+=2, yw++;
        cout.flush() << xw << " " << yw << "\n";
        if (xw==xb && yw==yb) {
            return 0;
        }
        cin >> xb >> yb;
        if (xb==a/2+1 && yb==b/2) {
            cout.flush() << xb << " " << yb << "\n";
            return 0;
        } else {
            xw--, yw-=2;
            cout << xw << " " << yw << "\n";
            if (xw==xb && yw==yb) {
                return 0;
            }
            cin >> xb >> yb;
            cout.flush() << a/2 << " " << b/2 << "\n";
            return 0;
        }
    }
    cout.flush() << "BLACK" << "\n";
    int lx, ly;
    cin >> lx >> ly;
    if (s[xb][yb]==2) {
        cout << a/2+1 << " " << b/2 << endl;
    }
    if (v[xb][yb]!=1) {
    vugras(xb, yb, lx, ly);
    if (kesz) {
        return 0;
    }
    cin >> lx >> ly;
    }
    xb=a/2, yb=b/2;
    xb-=2, yb--;
    cout.flush() << xb << " " << yb << "\n";
    if (xb==lx && yb==ly) {
        return 0;
    }
    cin >> lx >> ly;
    if (lx==a/2 && ly==b/2) {
        cout.flush() << a/2 << " " << b/2 << "\n";
        return 0;
    }
    xb++, yb+=2;
    cout.flush() << xb << " " << yb << "\n";
    if (xb==lx && yb==ly) {
        return 0;
    }
    cin >> lx >> ly;
    cout.flush() << a/2+1 << " " << b/2 << "\n";
    return 0;
}