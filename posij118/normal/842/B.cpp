#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, d, n, cnt;
    cnt=0;
    cin >> r >> d;
    cin >> n;
    int coord[n][3];
    for(int i=0; i<n; i++){
        cin >> coord[i][0] >> coord[i][1] >> coord[i][2];
        if(sqrt(coord[i][0]*coord[i][0]+coord[i][1]*coord[i][1])-coord[i][2]>=r-d && sqrt(coord[i][0]*coord[i][0]+coord[i][1]*coord[i][1])+coord[i][2]<=r) cnt++;
    }

    cout << cnt;

}