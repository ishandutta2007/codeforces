                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n, w, m;
vector <P> v[60];
int cnt[60], rem[60];

int main(){
    while(cin >> n >> w >> m){
        for(int i = 0; i < m; i++)
            v[i].clear();
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++)
            rem[i] = w * m;
        bool can = true;
        for(int i = 0; i < m; i++){
            int p = 0, sum = 0;
            while(rem[p] == 0)
                p++;
            while(sum < n * w){
                int t = min(rem[p], n * w - sum);
                rem[p] -= t;
                sum += t;
                v[i].push_back(P(p, t));
                cnt[p]++;
                if(cnt[p] > 2)
                    can = false;
                p++;
            }
        }
        if(can){
            cout.precision(7);
            cout.setf(ios::fixed | ios::showpoint);
            cout << "YES" << endl;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < v[i].size(); j++){
                    if(j > 0)
                        cout << ' ';
                    cout << v[i][j].first + 1 << ' ' << (double)v[i][j].second / m;
                }
                cout << endl;
            }
        }
        else cout << "NO" << endl;
    }
    return 0;
}