#include <bits/stdc++.h>
#define MAXN 300000
#define val first
#define t second

using namespace std;

string str;
bool viz[MAXN + 1];
pair <int, bool> v[MAXN + 1];


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,m,a,b,c;
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> m;
    for(i = 1; i <= m; i++) {
        cin >> v[i].val;
        str.clear();
        cin >> str;
        if(str[0] == 'U')
            v[i].t = 0;
        else
            v[i].t = 1;
    }
    sort(v + 1, v + m + 1);
    long long ans = 0;
    int cnt = 0;
    for(i = 1; i <= m && a > 0; i++)
        if(v[i].t == 0) {
            a--;
            ans += v[i].val;
            viz[i] = 1;
            cnt++;
        }
    for(i = 1; i <= m && b > 0; i++)
       if(v[i].t == 1) {
           b--;
           ans += v[i].val;
           viz[i] = 1;
           cnt++;
       }
    for(i = 1; i <= m && c > 0; i++)
       if(viz[i] == 0) {
           ans += v[i].val;
           c--;
           cnt++;
       }
     cout << cnt << " " << ans;
    //cin.close();
    //cout.close();
    return 0;
}