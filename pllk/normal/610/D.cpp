#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n;
map<int,vector<pair<int,int>>> mx, my;
map<int,vector<pair<int,int>>> ux, uy;
vector<int> vx,vy,vz;

map<int,int> yy;

#define N (1<<18)
int p[2*N];

vector<pair<pair<int,int>,pair<int,int>>> tt;

void muuta(int k, int x) {
    k += N;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = p[2*k]+p[2*k+1];
    }
}

int summa(int a, int b) {
    a += N; b += N;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += p[a++];
        if (b%2 == 0) s += p[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1,y2);
            mx[x1].push_back({y1,-1});
            mx[x1].push_back({y2,1});
            vx.push_back(x1);
            vz.push_back(y1);
            vz.push_back(y2);
        } else {
            if (x1 > x2) swap(x1,x2);
            my[y1].push_back({x1,-1});
            my[y1].push_back({x2,1});
            vy.push_back(y1);
            vz.push_back(y1);
        }
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    sort(vz.begin(),vz.end());
    int c = 0;
    for (int i = 0; i < vz.size(); i++) {
        if (i > 0 && vz[i-1] == vz[i]) continue;
        yy[vz[i]] = ++c;
    }
    ll t = 0;
    for (int i = 0; i < vx.size(); i++) {
        if (i > 0 && vx[i-1] == vx[i]) continue;
        int x = vx[i];
        sort(mx[x].begin(),mx[x].end());
        int c = 0;
        int a;
        for (int j = 0; j < mx[x].size(); j++) {
            if (c == 0) a = mx[x][j].first;
            c += mx[x][j].second;
            if (c == 0) {
                t += mx[x][j].first-a+1;
                tt.push_back(make_pair(make_pair(x,2),make_pair(yy[a],yy[mx[x][j].first])));
            }
        }
    }
    for (int i = 0; i < vy.size(); i++) {
        if (i > 0 && vy[i-1] == vy[i]) continue;
        int y = vy[i];
        sort(my[y].begin(),my[y].end());
        int c = 0;
        int a;
        for (int j = 0; j < my[y].size(); j++) {
            if (c == 0) a = my[y][j].first;
            c += my[y][j].second;
            if (c == 0) {
                t += my[y][j].first-a+1;
                tt.push_back(make_pair(make_pair(a,1),make_pair(yy[y],0)));
                tt.push_back(make_pair(make_pair(my[y][j].first,3),make_pair(yy[y],0)));
            }
        }
    }
    sort(tt.begin(),tt.end());
    for (int i = 0; i < tt.size(); i++) {
        int q = tt[i].first.second;
        //cout << "x " << tt[i].first.first << "\n";
        if (q == 1) {
            //cout << "1 " << tt[i].second.first << "\n";
            muuta(tt[i].second.first,1);
        }
        if (q == 2) {
            //cout << "2 " << tt[i].second.first << " " << tt[i].second.second << "\n";
            t -= summa(tt[i].second.first,tt[i].second.second);
        }
        if (q == 3) {
            //cout << "3 " << tt[i].second.first << "\n";
            muuta(tt[i].second.first,0);
        }
    }
    cout << t << "\n";
}