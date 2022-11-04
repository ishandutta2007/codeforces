#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000000


using namespace std;


int p[MAXN + 1];
bool viz[MAXN + 1];

vector <int> cycle[MAXN + 1];
vector <int> newcycle;
int fr[MAXN + 1];


int last[MAXN + 1];
int sol[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> p[i];
    int sz = 0;
    for(i = 1; i <= n; i++)
        if(viz[i] == 0) {
            int poz = i;
            sz++;
            while(viz[poz] == 0) {
                cycle[sz].push_back(p[poz]);
                viz[poz] = 1;
                poz = p[poz];
            }
            fr[cycle[sz].size()]++;
        }
    for(i = 2; i <= n; i += 2)
        if(fr[i] % 2 == 1) {
           cout << -1;
           return 0;
        }
    for(i = 1; i <= sz; i++)
        if(cycle[i].size() % 2 == 1) {
           newcycle.clear();
           int len = cycle[i].size();
           for(j = 0; j < len; j++)
              newcycle.push_back(0);
           int poz = 1;
           int cnt = 0;
           while(cnt < len) {
               newcycle[poz - 1] = cycle[i][cnt];
               cnt++;
               poz += 2;
               if(poz > len)
                 poz -= len;
           }
           for(j = 0; j < len; j++)
               sol[newcycle[(j - 1 + len) % len]] = newcycle[j];
           cycle[i].clear();
        }
    i = 1;
    while(i <= sz) {
        if(!cycle[i].empty() && cycle[i].size() % 2 == 0) {
            if(last[cycle[i].size()] == 0)
                last[cycle[i].size()] = i;
            else {
                newcycle.clear();
                int len = cycle[i].size();
                for(j = 0; j < 2 * len; j++) {
                    if(j % 2 == 0)
                        newcycle.push_back(cycle[last[len]][j / 2]);
                    else
                        newcycle.push_back(cycle[i][(j - 1) / 2]);
                }
                for(j = 0; j < 2 * len; j++) {
                    sol[newcycle[(j - 1 + 2 * len) % (2 * len)]] = newcycle[j];
                }
                last[len] = 0;
            }
        }
        i++;
    }
    for(i = 1; i <= n; i++)
        cout << sol[i] << " ";
    //cin.close();
    //cout.close();
    return 0;
}