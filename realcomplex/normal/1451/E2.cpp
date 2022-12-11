#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (1<<16)+10;
int a[N];
int cnt[N];
int f[N];

int main(){
    int n;
    cin >> n;
    int id = 0;
    int id2 = 0;
    set<int> dd;
    cnt[0] ++ ;
    for(int i = 2; i <= n; i ++) {
        cout << "XOR " << 1 << " " << i << endl;
        cin >> a[i];
        cnt[a[i]] ++ ;
        dd.insert(a[i]);
    }
    dd.insert(0);
    if(dd.size() == n){
        int i1 = 0, i2 = 0;
        for(int i = 2; i <= n; i ++ ){
            if(a[i] == 1){
                i1 = i;
            }
            else{
                if(a[i] % 2 == 1){
                    i2 = i;
                }
            }
        }
        int aa;
        cout << "AND " << 1 << " " << i1 << endl;
        cin >> aa;
        cout << "OR " << i1 << " " << i2 << endl;
        int bb;
        cin >> bb;
        if(bb % 2 == 0) aa |= 1;
        cout << "! ";
        for(int i = 1; i <= n; i ++ ){
            cout << (a[i] ^ aa) << " ";
        }
        cout << endl;
    }
    else{
        int el = 0;
        for(int i = 0 ; i < n; i ++ ){
            if(cnt[i] > 1){
                el = i;
            }
        }
        int idx = 0, idx1 = 0;
        for(int i = 1 ; i <= n; i ++ ){
            if(a[i] == el){
                if(idx == 0)idx = i;
                else idx1 = i;
            }
        }
        for(int j = 1; j <= n; j ++ ){
            f[j] = (a[j] ^ a[idx]);
        }
        cout << "AND " << idx << " " << idx1 << endl;
        int bb;
        cin >> bb;
        cout << "! ";
        for(int i = 1; i <= n; i ++ ){
            cout << (f[i] ^ bb) << " ";
        }
        cout << endl;
    }

    return 0;
}