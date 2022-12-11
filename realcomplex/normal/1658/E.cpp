#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct result{
    int val;
    int xi;
    int yi;
    bool operator< (result &qq) const {
        return val > qq.val;
    }
};

const int N = 2010;
int v[N][N];
int res[N][N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    vector<result> a0, a1;
    vector<result> cc;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cin >> v[i][j];
            cc.push_back({v[i][j], i, j});
            a0.push_back({i + j, i, j});
            a1.push_back({-i + j, i, j});
        }
    }
    sort(cc.begin(), cc.end());
    sort(a0.begin(), a0.end());
    sort(a1.begin(), a1.end());
    int p0 = 0;
    int p1 = 0;
    int p2 = (int)a0.size() - 1;
    int p3 = (int)a1.size() - 1;
    for(int i = 0 ; i < cc.size(); i ++ ){
        if(res[cc[i].xi][cc[i].yi] != 0) continue;
        res[cc[i].xi][cc[i].yi] = +1;
        while(p0 < a0.size() && a0[p0].val - cc[i].xi - cc[i].yi > k){
            if(res[a0[p0].xi][a0[p0].yi] == 0)
                res[a0[p0].xi][a0[p0].yi] = -1;
            p0 ++ ;
        }
        while(p1 < a1.size() && a1[p1].val + cc[i].xi - cc[i].yi > k){
            if(res[a1[p1].xi][a1[p1].yi] == 0)
                res[a1[p1].xi][a1[p1].yi] = -1;
            p1 ++ ;
        }
        while(p2 >= 0 && -a0[p2].val + cc[i].xi + cc[i].yi > k){
            if(res[a0[p2].xi][a0[p2].yi] == 0)
                res[a0[p2].xi][a0[p2].yi] = -1;
            p2 -- ;
        }
        while(p3 >= 0 && -a1[p3].val - cc[i].xi + cc[i].yi > k){
            if(res[a1[p3].xi][a1[p3].yi] == 0)
                res[a1[p3].xi][a1[p3].yi] = -1;
            p3 -- ;
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            if(res[i][j] == -1)
                cout << "G";
            else
                cout << "M";
        }
        cout << "\n";
    }
    return 0;
}