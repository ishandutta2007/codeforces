#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f3f;
const int N=55;
const int M=1005;

int n, m, valid;
string str;
string p[M];
int sol[30], bio[30][M], invalid[M];

void load() {
    scanf("%d", &n);
    cin >>str;
    scanf("%d", &m);
    for (int i=0; i<m; ++i) {
        cin >>p[i];
    }
}

void solve() {
    valid=m;
    for (int i=0; i<n; ++i) {
        if (str[i]=='*') continue;
        sol[str[i]-'a']=-INF;
    }
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (str[j]=='*') {
                if (sol[p[i][j]-'a']==-INF) {
                    invalid[i]=1;
                    --valid;
                    break;
                }
            }
            else {
                if (p[i][j]!=str[j]) {
                    invalid[i]=1;
                    --valid;
                    break;
                }
            }
        }
    }
    for (int i=0; i<str.size(); ++i) {
        if (str[i]!='*') continue;
        for (int j=0; j<m; ++j) {
            if (invalid[j]) continue;
            char ch=p[j][i];
            if (bio[ch-'a'][j]) continue;
            bio[ch-'a'][j]=1;
            sol[ch-'a']++;
        }
    }
    int res=0;
    for (int i='a'; i<='z'; ++i) {
        //printf("%c %d\n", i, sol[i-'a']);
        if (sol[i-'a']==valid) ++res;
    }
    printf("%d", res);
}

int main() {
    load();
    solve();
    return 0;
}