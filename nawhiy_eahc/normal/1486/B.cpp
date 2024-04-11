#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp1(pair<int, int> x, pair<int, int> y){
    return x.first < y.first;
}

bool cmp2(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

pair<int, int> coord[1000];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=0;i<n;i++){
            cin >> coord[i].first >> coord[i].second;
        }

        ll dx, dy;

        if(n%2) dx = dy = 1;
        else{
            sort(coord, coord + n, cmp1);
            dx = coord[n/2].first - coord[n/2 - 1].first + 1;
            sort(coord, coord + n, cmp2);
            dy = coord[n/2].second - coord[n/2 - 1].second + 1;
        }

        cout << dx * dy << "\n";
    }
}