#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 10000000
#define mp make_pair
#define fi first
#define se second

const int MAXN = (1e4);

int cnt[MAXN];

int main(){

    int n;
    cin >> n;
    int sk;
    for(int j = 0;j<n;j++){
        cin >> sk;
        cnt[sk]++;
    }
    int am = 0;
    for(int j = 0;j<MAXN;j++){
        if(cnt[j] >= 2){
            cnt[j+1] += cnt[j]-1;
            am += cnt[j]-1;
            cnt[j] = 1;
        }
    }
    cout << am;
    return 0;
}