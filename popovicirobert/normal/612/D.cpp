#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000000


using namespace std;

vector < pair <int, char> > events;
vector < pair <int, int> > sol;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    //ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&k);
    for(i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d" ,&l,&r);
        events.push_back({l, -1});
        events.push_back({r, 1});
    }
    sort(events.begin(), events.end());
    int cnt = 0;
    for(auto it : events) {
        if(it.second == -1) {
            if(cnt == k - 1)
              sol.push_back({it.first, 0});
        }
        else {
            if(cnt == k)
              sol[sol.size() - 1].second = it.first;
        }
        cnt -= it.second;
    }
    cout << sol.size() << endl;
    for(auto it : sol)
        printf("%d %d\n" ,it.first, it.second);
    //cin.close();
    //cout.close();
    return 0;
}