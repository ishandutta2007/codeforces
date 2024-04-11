#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9123;
int dd[N];

int main(){
    fastIO;
    for(int i = 0;i < N; i ++)
        dd[i] = (int)1e9 + 9;
    int n, m;
    cin >> n >> m;
    queue<int> f;
    f.push(n);
    dd[n] = 0;
    int nd;
    while(!f.empty()){
        nd = f.front();
        f.pop();
        if(nd * 2 < N and dd[nd] + 1 < dd[nd * 2]){
            dd[nd * 2] = dd[nd] + 1;
            f.push(nd * 2);
        }
        if(nd > 1 and dd[nd] + 1 < dd[nd - 1]){
            dd[nd - 1] = dd[nd] + 1;
            f.push(nd - 1);
        }
    }
    cout << dd[m];
    return 0;
}