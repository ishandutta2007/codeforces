#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
const int SQN = 330;
struct query{
    int l;
    int r;
    int idx;
    bool operator < (const query &b) const {
        return ( (l / SQN) == (b.l / SQN) ) ? r < b.r : l < b.l;
    }
};
int arr[N];
int cnt[N];
query Q[N];
int ans[N];
int n , q , temp = 0 , curl = 1 , curr = 0;
int update(int num , int val){
    if(num <= n){
        cnt[num] += val;
        if(cnt[num] == num)
            ++temp;
        if(cnt[num] == num + val)
            --temp;
    }
}
int main(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= q ; ++i){
        cin>> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }
    sort(Q + 1 , Q + 1 + q);
    for(int i = 1 ; i <= q ; ++i){
        while(curr < Q[i].r)
            update(arr[++curr] , 1);
        while(curl > Q[i].l)
            update(arr[--curl] , 1);
        while(Q[i].r < curr)
            update(arr[curr--] , -1);
        while(Q[i].l > curl)
            update(arr[curl++] , -1);
        ans[Q[i].idx] = temp;
    }
    for(int i = 1 ; i <= q ; ++i)
        cout << ans[i] << "\n";
}