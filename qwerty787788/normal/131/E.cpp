#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ferz {
    int id, x, y;
};

bool cmp1 (ferz f1, ferz f2) {
    if (f1.x < f2.x) return true;
    else return false;
}

bool cmp2 (ferz f1, ferz f2) {
    if (f1.y < f2.y) return true;
    else return false;
}

vector <ferz> a;
vector <int> x1[100001];
vector <int> y1[100001];
vector <int> d1[200004];
vector <int> d2[200004];

long long n, m;

long long s1[100000];
long long ans[9];
//
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //
    cin >> n >> m;
    int x, y;
    ferz f;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        f.x = x;
        f.y = y;
        f.id = i - 1;
        a.push_back(f);
        
    }
    //
    sort(a.begin(), a.end(), cmp2);
    for (int i = 0; i < a.size(); i++) {
        x1[a[i].x-1].push_back(a[i].id);
        d1[a[i].x+a[i].y-2].push_back(a[i].id);
        d2[a[i].x-a[i].y-1+n].push_back(a[i].id);
    }
    sort(a.begin(), a.end(), cmp1);
    for (int i = 0; i < a.size(); i++) {
        y1[a[i].y-1].push_back(a[i].id);
    }
    //
    for (int i = 0; i < n; i++) {
        if (x1[i].size() <= 1) {

        } else {
            if (x1[i].size() >= 2) {
                s1[x1[i][0]] += 1;
                s1[x1[i][x1[i].size()-1]] += 1;
                for (int j = 1; j < x1[i].size() - 1; j++)
                    s1[x1[i][j]] += 2;
            }
        }       
    }
    //
    for (int i = 0; i < n; i++) {
        if (y1[i].size() <= 1) {

        } else {
            if (y1[i].size() >= 2) {
                s1[y1[i][0]] += 1;
                s1[y1[i][y1[i].size()-1]] += 1;
                for (int j = 1; j < y1[i].size() - 1; j++)
                    s1[y1[i][j]] += 2;
            }
        }       
    }   
    //
    for (int i = 0; i < 2*n - 1; i++) {
        if (d1[i].size() <= 1) {

        } else {
            if (d1[i].size() >= 2) {
                s1[d1[i][0]] += 1;
                s1[d1[i][d1[i].size()-1]] += 1;
                for (int j = 1; j < d1[i].size() - 1; j++)
                    s1[d1[i][j]] += 2;
            }
        }       
    }
    //
    for (int i = 0; i < 2*n - 1; i++) {
        if (d2[i].size() <= 1) {

        } else {
            if (d2[i].size() >= 2) {
                s1[d2[i][0]] += 1;
                s1[d2[i][d2[i].size()-1]] += 1;
                for (int j = 1; j < d2[i].size() - 1; j++)
                    s1[d2[i][j]] += 2;
            }
        }       
    }
    //
    for (int i = 0; i <m; i++)
        ans[s1[i]]++;
    //
    for (int i = 0; i < 9; i++)
        cout << ans[i] << " ";
    cout << endl;
    //
    return 0;
}