#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
bool used[1010][1010];
void F(int x1,int y1,int x2,int y2){
     for (int i=min(x1,x2);i<=max(x1,x2);i++) used[y1][i]=true;
     for (int i=min(y1,y2);i<=max(y1,y2);i++) used[i][x2]=true;
}
int32_t main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/

    int xA,yA,xB,yB,xC,yC;cin>>xA>>yA>>xB>>yB>>xC>>yC;
    int yM=0;
    int xM=0;
    for (int i=0;i<=1000;i++){
        if (abs(xA-i)+abs(xB-i)+abs(xC-i)<abs(xA-xM)+abs(xB-xM)+abs(xC-xM)) xM=i;
    }
    for (int i=0;i<=1000;i++){
        if (abs(yA-i)+abs(yB-i)+abs(yC-i)<abs(yA-yM)+abs(yB-yM)+abs(yC-yM)) yM=i;
    }
    F(xA,yA,xM,yM);
    F(xB,yB,xM,yM);
    F(xC,yC,xM,yM);
    vector<pair<int,int> >ans;
    for (int i=0;i<=1000;i++){
        for (int j=0;j<=1000;j++){
            if (used[i][j]) ans.push_back({j,i});
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;
}
/*
7
0110010
1 2
1 3
1 4
2 5
2 6
3 7
*/