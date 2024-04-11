#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9 + 7;

int main(){
    long long n, x, y, sh;
    cin >> n >> x >> y;

    long long l[n], r[n];
    pair<long long, long long> val[2*n];
    for(long long i = 0; i<n; i++){
        cin >> l[i] >> r[i];
        val[2*i] = make_pair(l[i], -1);
        val[2*i + 1] = make_pair(r[i], 1);
    }

    long long cur = 0;
    long long ans = 0;
    sort(val, val + 2*n);

    pair<long long, long long> times[2*n];
    for(long long i = 0; i<2*n; i++){
        cur -= val[i].second;
        times[i] = make_pair(val[i].first, cur);
    }

    vector<long long> larger;
    long long closest[2*n];
    for(long long i = 2*n - 1; i >= 0; i--){
        while(1){
            if(larger.size() == 0) break;
            if(times[i].second >= times[larger[larger.size() - 1]].second) larger.pop_back();
            else break;
        }

        if(larger.size() == 0) closest[i] = 1e9 + 7;
        else closest[i] = times[larger[larger.size() - 1]].first;
        larger.push_back(i);
    }

    cur = 0;
    for(long long i = 0; i<2*n - 1; i++){
        if(times[i].second > cur){
                cur++;
                ans += x;
        }

        else if(cur > times[i].second){
            if(closest[i] == 1e9 + 7) cur--;
            else{
                if((closest[i] - times[i].first) * y > x) cur--;
            }
        }

        sh = cur * (times[i + 1].first - times[i].first);
        sh %= M;

        ans += (sh * y) % M;
        ans %= M;

    }

    cout << ans;



}