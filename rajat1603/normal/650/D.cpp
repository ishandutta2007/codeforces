#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
const int MX = 8e5 + 5;
const int SZ = 2e7 + 7;
int n , m;
pair < int , pair < int , int > > inp[MX];
int arr[N];
int a[N];
int b[N];
int lis;
int mx = 0;
int idx = 0;
struct node{
    int val;
    int left;
    int right;
    node(int _val = 0 , int _left = 0 , int _right = 0){
        val = _val;
        left = _left;
        right = _right;
    }
};
node dummy;
int rootl[N];
int rootr[N];
int ll[N];
int suf[N];
node segtree[SZ];
int newnode(int v , int l , int r){
    ++idx;
    segtree[idx] = node(v , l , r);
    return idx;
}
int update(int l , int r , int idx , int value , int lst){
    if(l == r){
        return newnode(max(segtree[lst].val , value) , 0 , 0);
    }
    int mid = l + r >> 1;
    if(idx <= mid){
        return newnode(max(segtree[lst].val , value) , update(l , mid , idx , value , segtree[lst].left) , segtree[lst].right);
    }
    return newnode(max(segtree[lst].val , value) , segtree[lst].left , update(mid + 1 , r , idx , value , segtree[lst].right));
}
int query(int l , int r , int ql , int qr , int node){
    if(l > qr || r < ql || ql > qr || !node){
        return 0;
    }
    if(l >= ql && r <= qr){
        return segtree[node].val;
    }
    int mid = l + r >> 1;
    return max(query(l , mid , ql , qr , segtree[node].left) , query(mid + 1 , r , ql , qr , segtree[node].right));
}
void brute(int a , int b){
    int tmp = arr[a];
    arr[a] = b;
    int dp[n + 1];
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = 1;
        for(int j = 1 ; j < i ; ++j){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        ans = max(ans , dp[i]);
    }
    cout << "Brute ans : " << ans << endl;
    arr[a] = tmp;
}
int main(){
    srand(time(NULL));
    scanf("%d %d" , &n , &m);
    //cout << n << " " << m << endl;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp[i].first);
        //inp[i].first = (rand() % 100) + 1;
        inp[i].second = make_pair(-1 , i);
        //cout << inp[i].first << " ";
    }
    //cout << endl;
    for(int i = n + 1 ; i <= m + n ; ++i){
        //inp[i].second.first = 1 + (rand() % n);
        //inp[i].first = 1 + (rand() % 100);
        //cout << inp[i].second.first << " " << inp[i].first << endl;
        scanf("%d %d" , &inp[i].second.first , &inp[i].first);
        inp[i].second.second = i;
        a[i - n] = inp[i].second.first;
    }
    sort(inp + 1 , inp + 1 + m + n);
    inp[0].first = -1;
    for(int i = 1 ; i <= m + n ; ++i){
        mx += (inp[i - 1].first != inp[i].first);
        if(inp[i].second.second <= n){
            arr[inp[i].second.second] = mx;
        }
        else{
            b[inp[i].second.second - n] = mx;
        }
    }
    dummy = node();
    rootl[0] = 0;
    segtree[0] = dummy;
    for(int i = 1 ; i <= n ; ++i){
        int tmp = query(1 , mx ,  1 , arr[i] - 1 , rootl[i - 1]);
        rootl[i] = update(1 , mx , arr[i] , tmp + 1 , rootl[i - 1]);
    }
    rootr[n + 1] = 0;
    for(int i = n ; i >= 1 ; --i){
        int tmp = query(1 , mx , arr[i] + 1 , mx , rootr[i + 1]);
        rootr[i] = update(1 , mx , arr[i] , tmp + 1 , rootr[i + 1]);
    }
    lis = query(1 , mx , 1 , mx , rootl[n]);
    for(int i = 1 ; i <= n ; ++i){
        int tmp = query(1 , mx , arr[i] + 1 , mx , rootr[i + 1]);
        if(1 + tmp + query(1 , mx , 1 , arr[i] - 1 , rootl[i - 1]) != lis){
            ll[i] = n + 1;
        }
        else{
            int l = 0;
            int r = i - 1;
            while(l < r){
                int mid = l + r >> 1;
                int val = query(1 , mx , 1 , arr[i] - 1 , rootl[mid]) + 1 + tmp;
                if(val == lis){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            ll[i] = l;
        }
    }
    suf[n + 1] = n + 1;
    suf[n] = ll[n];
    for(int i = n - 1 ; i >= 1 ; --i){
        suf[i] = min(suf[i + 1] , ll[i]);
    }
    for(int i = 1 ; i <= m ; ++i){
        int x = a[i];
        int y = b[i];
        //brute(x , y);
        int ans = lis - 1;
        int plis = query(1 , mx , 1 , y - 1 , rootl[x - 1]) + 1 + query(1 , mx , y + 1 , mx , rootr[x + 1]);
        ans = max(ans , plis);
        if(ans < lis){
            if(suf[x + 1] < x){
                ans = max(ans , lis);
            }
            else if(query(1 , mx , 1 , mx , rootl[x - 1]) == lis){
                ans = max(ans , lis);
            }
            else if(query(1 , mx , 1 , mx , rootr[x + 1]) == lis){
                ans = max(ans , lis);
            }
        }
        printf("%d\n" , ans);
    }
}