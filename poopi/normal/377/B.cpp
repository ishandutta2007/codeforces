                                        /* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

struct tri{
    int first, second, idx;
    tri(){}
    tri(int f, int s, int i){
        first = f, second = s, i = idx;
    }
    bool operator < (const tri &a) const{
        if(first != a.first)
            return first < a.first;
        return second < a.second;
    }
};

int n, m, v;
tri s[100010];
P b[100010];
int res[100010];
priority_queue <P> q;

int64 calc(int d){
    while(!q.empty())
        q.pop();
    int ptr = m - 1;
    int end = n - 1;
    int64 sum = 0;
    while(end >= 0 && s[end].first >= b[ptr].first){
        q.push(P(-s[end].second, s[end].idx));
        end--;
    }
    while(!q.empty() && ptr >= 0){
        sum += -q.top().first;
        int idx = q.top().second;
        q.pop();
        for(int i = 0; i < d && ptr >= 0; i++, ptr--)
            res[b[ptr].second] = idx + 1;
        while(ptr >= 0 && end >= 0 && s[end].first >= b[ptr].first){
            q.push(P(-s[end].second, s[end].idx));
            end--;
        }
    }
    if(ptr >= 0)
        return v + 1;
    return sum;
}

int main(){
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    for(int i = 0; i < n; i++){
        cin >> s[i].first;
        s[i].idx = i;
    }
    for(int i = 0; i < n; i++)
        cin >> s[i].second;
    sort(b, b + m);
    sort(s, s + n);
    int l = 1, r = m + 1;
    while(l < r){
        int mid = (l + r) / 2;
        if(calc(mid) <= v)
            r = mid;
        else l = mid + 1;
    }
    if(l <= m){
        calc(l);
        cout << "YES" << endl;
        for(int i = 0; i < m; i++)
            cout << res[i] << ' ';
        cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}