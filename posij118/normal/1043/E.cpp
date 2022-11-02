#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;
    long long x[n], y[n];
    long long xsum, ysum;
    long long ans[n];
    xsum = 0;
    ysum = 0;

    pair<pair<long long, int>, pair<long long, long long> > cont[n];
    for(int i = 0; i<n; i++){
        cin >> x[i] >> y[i];
        ysum += y[i];
        cont[i] = make_pair(make_pair(x[i] - y[i], i), make_pair(x[i], y[i]));
    }

    sort(cont, cont + n);
    for(int i = 0; i<n; i++){
        if(i == 0) ysum -= cont[i].second.second;
        if(i > 0) xsum += cont[i - 1].second.first;


        ans[cont[i].first.second] = xsum + i * cont[i].second.second
            + ysum + (n - 1 - i) * cont[i].second.first;

        if(i != n - 1) ysum -= cont[i + 1].second.second;

    }
    

    for(int i = 0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        ans[a] -= min(x[a] + y[b], y[a] + x[b]);
        ans[b] -= min(x[a] + y[b], y[a] + x[b]);
    }

    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }






}