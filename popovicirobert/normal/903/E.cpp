#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 5e3;

string str[MAXN + 1];
int fr[26];

bool ok[MAXN + 1];

bool flag = 0;

int n, len;

inline bool check(string aux) {
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        vector < pair <char, char> > v;
        for(int j = 1; j <= len; j++) {
            if(str[i][j] != aux[j]) {
               cnt++;
               v.push_back({str[i][j], aux[j]});
            }
        }
        if(cnt > 2)
            return 0;
        if(cnt == 0 && flag == 0)
            return 0;
        if(cnt == 1)
            return 0;
        if(cnt == 2 && !(v[0].first == v[1].second && v[0].second == v[1].first)) {
            return 0;
        }
    }
    return 1;
}

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> n >> len;
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        str[i] = " " + str[i];
        if(i == 1)
        for(j = 1; j <= len; j++)
            fr[str[i][j] - 'a']++;
    }
    for(i = 0; i < 26; i++) {
       if(fr[i] > 1) {
            flag = 1;
       }
    }
    string aux = str[1];
    if(check(aux) && flag) {
        for(i = 1; i <= len; i++)
            cout << aux[i];
        return 0;
    }
    if(len <= 50) {
        for(int a = 1; a <= len; a++) {
            for(int b = a + 1; b <= len; b++) {
                swap(aux[a], aux[b]);
                if(aux[a] != aux[b]) {
                    if(check(aux)) {
                        for(i = 1; i <= len; i++)
                            cout << aux[i];
                        return 0;
                    }
                }
                swap(aux[a], aux[b]);

            }
        }
    }
    else {
        int cnt = 0;
        for(i = 1; i <= len; i++) {
            if(str[1][i] == str[2][i])
                ok[i] = 1;
            else
                cnt++;
        }
        if(cnt > 4) {
            cout << -1;
            return 0;
        }
        for(int a = 1; a <= len; a++)
        if(ok[a] == 0) {
            for(int b = a + 1; b <= len; b++)
            if(ok[b] == 0) {
                swap(aux[a], aux[b]);
                if(aux[a] != aux[b]) {
                    if(check(aux)) {
                        for(i = 1; i <= len; i++)
                            cout << aux[i];
                        return 0;
                    }
                }
                swap(aux[a], aux[b]);

            }
        }
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}