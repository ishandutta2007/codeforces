#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int M = (int)5e5 + 10;
int cnt[M];
int nex[M];
int A[N];

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }

    for(int i = 0 ; i <= A[n]; i ++ ) {
        cnt[i] = 0, nex[i] = 0;
    }
    for(int i = 1; i <= n; i ++ ) cnt[A[i]] ++ ;
    for(int i = 0 ; i <= A[n]; i ++ ){
        if(cnt[i] > 0)
            a.push_back(i);
    }
    for(int e = 1; e <= n-1; e ++ ){
        vector<int> b;
        for(int i = 0 ; i < a.size(); i ++ ){
            if(cnt[a[i]] > 1){
                if(nex[0] == 0){
                    b.push_back(0);
                }
                nex[0] += cnt[a[i]] - 1;
            }
            if(i + 1 < a.size()){
                if(nex[a[i + 1] - a[i]] == 0){
                    b.push_back(a[i + 1] - a[i]);
                }
                nex[a[i + 1] - a[i]] += 1;
            }
        }
        sort(b.begin(), b.end());
        for(auto x : a){
            cnt[x] = 0;
        }
        for(auto x : b){
            cnt[x] = nex[x];
            nex[x] = 0;
        }
        swap(b, a);
    }
    cout << a[0] << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}