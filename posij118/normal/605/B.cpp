#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y, ptr, ptr2;
    cin >> n >> m;

    pair<int, int> edg[m];
    pair<int, int> mst[n - 1];
    pair<int, int> oth[m - n + 1];
    int ans[m][2];
    ptr = 0;
    ptr2 = 0;

    for(int i = 0; i<m; i++){
        cin >> x >> y;
        edg[i] = make_pair(x, y);
        if(y == 1){
            mst[ptr] = make_pair(x, i);
            ptr++;
        }

        else{
            oth[ptr2] = make_pair(x, i);
            ptr2++;
        }
    }

    int nedg[m - n + 1][2];
    ptr = 0;
    x = 1;
    y = 2;

    while(ptr < m - n + 1){
        nedg[ptr][0] = x;
        nedg[ptr][1] = y;

        if(y == x + 1){
            y++;
            x = 1;
        }

        else x++;
        ptr++;
    }

    sort(mst, mst + n - 1);
    sort(oth, oth + m - n + 1);

    for(int i = 0; i<n - 1; i++){
        ans[mst[i].second][0] = 1;
        ans[mst[i].second][1] = i + 2;
    }

    for(int i = 0; i<m - n + 1; i++){
        if(mst[nedg[i][0] - 1].first > oth[i].first || mst[nedg[i][1] - 1].first > oth[i].first){
            cout << -1;
            return 0;
        }

        ans[oth[i].second][0] = nedg[i][0] + 1;
        ans[oth[i].second][1] = nedg[i][1] + 1;

    }

    for(int i = 0; i<m; i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }


}