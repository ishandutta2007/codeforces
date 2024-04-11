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

int n, m, res;
map <int, int> mp;
vector <int> v[5000];

int main(){
    cin >> m;
    int x;
    for(int i = 0; i < m; i++){
        cin >> x;
        if(mp.find(x) == mp.end())
            mp[x] = n++;
        v[mp[x]].push_back(i);
        res = max(res, (int)v[mp[x]].size());
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int cnt = 1, pa = 0, pb = 0;
            int a = i, b = j;
            if(v[a][0] > v[b][0])
                swap(a, b);
            bool flag = true;
            while(flag){
                while(pb < v[b].size() && v[b][pb] < v[a][pa])
                    pb++;
                if(pb == v[b].size())
                    flag = false;
                else cnt++;
                swap(a, b);
                swap(pa, pb);
            }
            res = max(res, cnt);
        }
    }
    cout << res << endl;
    return 0;
}