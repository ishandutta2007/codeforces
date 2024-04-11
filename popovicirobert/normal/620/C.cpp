#include <bits/stdc++.h>
#define long long ll
#define MAXN 300000

using namespace std;

int fr[MAXN + 1];
pair <int, int> v[MAXN + 1];
pair <int, int> sol[MAXN + 1];
int vec[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        scanf("%d" ,&v[i].first);
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++)
        if(v[i].first == v[i - 1].first)
            vec[v[i].second] = vec[v[i - 1].second];
        else
            vec[v[i].second] = i;
    int cnt = 0;
    i = 1;
    while(i <= n) {
        int j = i;
        while(j <= n && fr[vec[j]] < 1) {
            fr[vec[j]]++;
            j++;
        }
        if(j <= n)
            fr[vec[j]]++;
        if(j <= n) {
           cnt++;
           sol[cnt] = {i, j};
        }
        else {
          if(cnt == 0) {
             cout << -1;
             return 0;
          }
          sol[cnt].second = n;
        }
        i = j + 1;
        for(j = sol[cnt].second; j >= sol[cnt].first; j--)
            fr[vec[j]] = 0;
    }
    cout << cnt << endl;
    for(i = 1; i <= cnt; i++)
       printf("%d %d\n" ,sol[i].first, sol[i].second);
    //cin.close();
    //cout.close();
    return 0;
}