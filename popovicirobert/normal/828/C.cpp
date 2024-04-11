#include <bits/stdc++.h>
#define MAXN 1000000
#define pos first

using namespace std;

string str[MAXN + 1];
char sol[2 * MAXN + 1];

pair <int, int> v[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,n,j,k;
    ios::sync_with_stdio(false);
    cin >> n;
    int sz = 0;
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        cin >> k;
        for(j = 1; j <= k; j++) {
            sz++;
            cin >> v[sz].pos;
            v[sz].second = i;
        }
    }
    sort(v + 1, v + sz + 1);
    int last = 0;
    for(i = 1; i <= sz; i++) {
        //printf("%d %d\n" ,v[i].pos,v[i].second);
       //printf("%d\n" ,last);
        if(v[i].pos > last) {
            for(j = v[i].pos; j < v[i].pos + (int)str[v[i].second].size(); j++) {
                sol[j] = str[v[i].second][j - v[i].pos];
            }
            last = v[i].pos + (int)str[v[i].second].size() - 1;
        }
        else {
            for(j = last + 1; j < v[i].pos + (int)str[v[i].second].size(); j++)
                sol[j] = str[v[i].second][j - v[i].pos];
            last = max(last, v[i].pos + (int)str[v[i].second].size() - 1);
        }
       // for(j = 1;  j <= last; j++)
       //     printf("%c" ,sol[j]);
       // printf("\n");
    }
    for(i = 1; i <= last; i++) {
        if(isalpha(sol[i]))
            cout << sol[i];
        else
            cout << 'a';
    }
    //cin.close();
    //cout.close();
    return 0;
}