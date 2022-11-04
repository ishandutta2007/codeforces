#include <bits/stdc++.h>
#define MAXN 100000
#define zeros(x) (x & (-x))

using namespace std;

int aib[4][11][10][MAXN + 1];
char ch[] = {'A', 'T', 'G', 'C'};
int n;

inline void update(int p, int len, int r, int pos, int val) {
    for(int i = pos; i <= n; i += zeros(i))
        aib[p][len][r][i] += val;
}

inline int query(int p, int len, int r, int pos) {
    int ans = 0;
    for(int i = pos; i > 0; i -= zeros(i))
        ans += aib[p][len][r][i];
    return ans;
}

string str, e;

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, p, len, r, q ,pos;
    char x;
    ios::sync_with_stdio(false);
    cin >> str;
    n = str.size();
    for(p = 0; p < 4; p++)
      for(len = 1; len <= 10; len++)
       for(r = 0; r < len; r++)
        for(i = r; i <= n; i += len)
            if(i > 0 && str[i - 1] == ch[p])
                update(p, len, r, i, 1);
    cin >> q;
    while(q > 0) {
        q--;
        int t;
        cin >> t;
        if(t == 1) {
            cin >> pos >> x;
            int p1, p2;
            p1 = p2 = 0;
            while(ch[p1] != str[pos - 1])
                p1++;
            while(ch[p2] != x)
                p2++;
            for(len = 1; len <= 10; len++) {
                update(p1, len, pos % len, pos, -1);
                update(p2, len, pos % len, pos, 1);
            }
            str[pos - 1] = x;
        }
        else {
            e.clear();
            int l, r;
            cin >> l >> r >> e;
            int m = e.size();
            int ans = 0;
            for(i = 1; i <= m; i++) {
                p = 0;
                while(ch[p] != e[i - 1])
                    p++;
                ans += query(p, m, (l + i - 1) % m, r) - query(p, m, (l + i - 1) % m, l - 1);
                //printf("%d %d %c\n" ,ans,i,e[i - 1]);
            }
            //printf("\n");
            cout << ans << endl;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}