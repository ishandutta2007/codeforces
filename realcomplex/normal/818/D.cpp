#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

const int MAXN = int(1e6)+5;
vector<int>times[MAXN];
int colorA[MAXN];

void ini(){
    for(int j = 1;j<MAXN;j++) colorA[j]+=colorA[j-1];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a;
    cin >> n >> a;
    int col;
    for(int j = 1;j<=n;j++){
        cin >> col;
        times[col].push_back(j);
        if(col == a) colorA[j]++;
    }
    ini();
    bool can;
    for(int j = 1;j<MAXN;j++){
        if(j == a) continue;
        can = true;
        if(times[a].size()>times[j].size())continue;
        for(int i = 0;i<times[j].size();i++){
            if(colorA[times[j][i]] >= i+1) can = false;
        }
        if(can == true){
            cout << j;
            exit(0);
        }
    }
    cout << -1;
    return 0;
}