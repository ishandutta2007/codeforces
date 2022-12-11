#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<int,int> idx;
int cnt;

int add(int x){
    if(idx.count(x))
        return idx[x];
    else
        return idx[x]=++cnt;
}

const int N = 2002;
int a[N];
int dd[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> a[i];
        a[i] = add(a[i]);
    }
    int val;
    int res = n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= cnt; j ++ ){
            dd[j] = 0;
        }
        for(int j = 1; j <= n ; j ++ )
            dd[a[j]] ++ ;
        val = 0;
        for(int j = 1; j <= cnt; j  ++ )
            val += (dd[j] >= 2);
        if(val == 0){
            res = 0;
            break;
        }
        for(int j = i ; j <= n; j ++ ){
            if(dd[a[j]] == 2){
                val -- ;
            }
            dd[a[j]] -- ;
            if(val == 0)
                res = min(res, j - i + 1);
        }
    }
    cout << res;
    return 0;   
}