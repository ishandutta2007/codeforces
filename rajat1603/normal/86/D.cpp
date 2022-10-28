#include "bits/stdc++.h"
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 200001;
const int M = 1000001;
const int SQN = 500;
int n , q;
int arr[N];
long long print[N];
int cnt[M] = {0};
struct query{
    int l;
    int r;
    int idx;
    int block;
    query(){}
    query(int _l , int _r , int _id){
        l = _l;
        r = _r;
        idx = _id;
        block = _l/SQN;
    }
    bool operator < (const query &b) const {
        if(block != b.block){
            return block < b.block;
        }
        return r < b.r;
    }
};
query Q[N];
int main(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= q ; ++i){
        int l , r;
        cin >> l >> r;
        Q[i] = query(l,r,i);
    }
    sort(Q + 1 , Q + 1 + q);
    long long ans = 0;
    int curl = 1 , curr = 0;
    for(int i = 1 ; i <= q ; ++i){
        int l = Q[i].l;
        int r = Q[i].r;
        int id = Q[i].idx;
        while (curr < r){
            ++curr;
            ans += 1LL * (1LL + cnt[arr[curr]] + cnt[arr[curr]]) * arr[curr];
            ++cnt[arr[curr]];
        }
        while (l < curl){
            --curl;
            ans += 1LL * (1LL + cnt[arr[curl]] + cnt[arr[curl]]) * arr[curl];
            ++cnt[arr[curl]];
        }
        while (r < curr){
            ans -= 1LL * (cnt[arr[curr]] + cnt[arr[curr]] - 1LL) * arr[curr];
            --cnt[arr[curr--]];
        }
        while (curl < l){
            ans -= 1LL * (cnt[arr[curl]] + cnt[arr[curl]] - 1LL) * arr[curl];
            --cnt[arr[curl++]];
        }
        print[id] = ans;
    }
    for(int i = 1 ; i <= q ; ++i){
        cout << print[i] << "\n";
    }
}