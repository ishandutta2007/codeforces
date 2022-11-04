#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = 100;

string str[MAXN];

int n, m;

inline bool okl(int l) {
    int c = 0;
    while(c < m && str[l][c] == str[l][0])
        c++;
    return c == m;
}

inline bool okc(int c) {
    int l = 0;
    while(l < n && str[l][c] == str[0][c])
        l++;
    return l == n;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> str[i];
    bool flag = 0;
    if(n % 3 == 0) {
        i = 0;
        while(i < n && str[i][0] == str[0][0] && okl(i))
           i++;
        if(i == n / 3) {
            while(i < n && str[i][0] == str[n / 3][0] && okl(i))
                i++;
            if(i == 2 * n / 3 && str[i][0] != str[0][0]) {
                 while(i < n && str[i][0] == str[2 * n / 3][0] && okl(i))
                        i++;
                 if(i == n)
                    flag = 1;
            }
        }
    }
    if(m % 3 == 0) {
        i = 0;
        while(i < m && str[0][i] == str[0][0] && okc(i))
            i++;
        if(i == m / 3) {
            while(i < m && str[0][i] == str[0][m / 3] && okc(i))
                i++;
            if(i == 2 * m / 3 && str[0][i] != str[0][0]) {
                while(i < m && str[0][i] == str[0][2 * m / 3] && okc(i))
                    i++;
                if(i == m)
                    flag = 1;
            }
        }
    }
    if(flag == 1)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}