#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e9
#define fi first
#define se second

int cnt[105];

int main(){

    int n,m;
    cin >> n >> m;
    int val,ind;
    int x;
    for(int i = 0;i<m;i++){
        val = -1;
        ind = 0;
        for(int j = 0;j<n;j++){
            cin >> x;
            if(x>val){
                val = x;
                ind = j;
            }
        }
        cnt[ind]++;
    }
    val = -1;
    ind = 0;
    for(int x = 0;x<105;x++){
        if(cnt[x]>val){
            val = cnt[x];
            ind = x;
        }
    }
    cout << ind+1;
    return 0;
}