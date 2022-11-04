#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))

using namespace std;

string str;

bool ok[30];
bool f[30];

int main() {
    FILE *fi, *fout;
    //fi = fopen("B.in" ,"r");
    //fout = fopen("B.out" ,"w");
    //fi = stdin;
    //fout = stdout;
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < 26; i++) {
        ok[i] = 1;
    }
    bool flag = 0;
    char sol = 0;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        cin >> str;
        if(ch == '?') {
            if(flag == 1 && str[0] != sol)
                ans++;
            ok[str[0] - 'a'] = 0;
        }
        else {
             memset(f, 0, sizeof(f));
             for(auto it : str) {
                    f[it - 'a'] = 1;
             }
             if(ch == '.') {
                for(auto it : str) {
                    ok[it - 'a'] = 0;
                }
             }
             else {
                for(j = 0; j < 26; j++) {
                    if(f[j] == 0)
                        ok[j] = 0;
                }
             }
             if(flag == 1 && f[sol - 'a'] == 1 && ch == '!') {
                 ans++;
             }
        }
        int cnt = 0;
             for(j = 0; j < 26; j++) {
                if(ok[j] == 1) {
                    cnt++;
                    sol = j + 'a';
                }
             }
             if(cnt == 1) {
                flag = 1;
             }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    //fclose(fi);
    //fclose(fout);
    return 0;
}