#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 30;
struct data{
    int sum;
    int lft;
    int rgt;
    data(){
        sum = 0;
        lft = 0;
        rgt = 0;
    }
    data(int _sum , int _lft , int _rgt){
        sum = _sum;
        lft = _lft;
        rgt = _rgt;
    }
};
data segtree[N * LN * 2];
int root1[N];
int root2[N];
int cur;
int dummy;
void insert(int &node , int last , int l , int r , int val){
    if(l == r){
        node = ++cur;
        segtree[node].lft = dummy;
        segtree[node].rgt = dummy;
        segtree[node].sum = segtree[last].sum + 1;
    }
    else{
        int mid = l + r >> 1;
        if(val <= mid){
            node = ++cur;
            segtree[node].sum = segtree[last].sum + 1;
            segtree[node].rgt = segtree[last].rgt;
            insert(segtree[node].lft , segtree[last].lft , l , mid , val);
        }
        else{
            node = ++cur;
            segtree[node].sum = segtree[last].sum + 1;
            segtree[node].lft = segtree[last].lft;
            insert(segtree[node].rgt , segtree[last].rgt , mid + 1 , r , val);
        }
    }
}
void pre(){
    dummy = 0;
    segtree[dummy].sum = 0;
    segtree[dummy].lft = dummy;
    segtree[dummy].rgt = dummy;
    cur = 0;
}
int n;
int a , b;
vector < int > v[N];
int subtree[N];
int ans[N];
int tin[N];
int tout[N];
int timer;
int start;
vector < int > out[N];
vector < int > in[N];
void dfs(int node){
    tin[node] = ++timer;
    subtree[node] = 1;
    for(int next : v[node]){
        dfs(next);
        subtree[node] += subtree[next];
    }
    tout[node] = timer;
}
int query(int l , int r , int node , int ql , int qr){
    if(!segtree[node].sum){
        return -1;
    }
    if(r < ql){
        return -1;
    }
    if(l == r){
        return l;
    }
    int mid = l + r >> 1;
    if(ql > mid){
        return query(mid + 1 , r , segtree[node].rgt , ql , qr);
    }
    int ret = query(l , mid , segtree[node].lft , ql , qr);
    if(ret == -1){
        ret = query(mid + 1 , r , segtree[node].rgt , ql , qr);
    }
    return ret;
}
int find1(int idx , int val){
    return query(1 , n , root1[idx] , val , n);
}
int find2(int idx , int val){
    return query(1 , n , root2[idx] , val , n);
}
set < int > s[N];
int stk[N];
int siz;
int find3(int node , int val){
    if(subtree[start] - subtree[node] < val){
        return -1;
    }
    int l = 1;
    int r = siz;
    while(l < r){
        int mid = l + r + 1 >> 1;
        int x = stk[mid];
        if(subtree[x] - subtree[node] >= val){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    if(subtree[stk[l]] - subtree[node] < val){
        return -1;
    }
    return subtree[stk[l]] - subtree[node];
}
void dfs2(int node , int parent){
    int mx = -1;
    stk[++siz] = node;
    for(int next : v[node]){
        dfs2(next , node);
        if(mx == -1){
            mx = next;
        }
        else if(subtree[next] > subtree[mx]){
            mx = next;
        }
    }
    pair < int , int > who;
    who = make_pair(-1 , -1);
    pair < int , int > whomn;
    whomn = make_pair(n + 1 , n + 1);
    int mxx = - 1 , smxx = -1;
    for(int next : v[node]){
        who = max(who , make_pair(subtree[next] , next));
        whomn = min(whomn , make_pair(subtree[next] , next));
        if(subtree[next] > mxx){
            smxx = mxx;
            mxx = subtree[next];
        }
        else if(subtree[next] > smxx){
            smxx = subtree[next];
        }
    }
    if(parent){
        int val = n - subtree[node];
        who = max(who , make_pair(val , parent));
        whomn = min(whomn , make_pair(val , parent));
        if(val > mxx){
            smxx = mxx;
            mxx = val;
        }
        else if(val > smxx){
            smxx = val;
        }
    }
    if(who.second == parent){
        int l = 0;
        int r = n;
        while(l < r){
            int mid = l + r >> 1;
            bool ok = 1;
            if(smxx > mid){
                ok = 0;
            }
            else{
                if(mxx > mid){
                    int reqx = mxx - mid;//x >= reqx
                    int val1 = find1(tin[node] - 1 , reqx);
                    int val2 = find2(tout[node] + 1 , reqx);
                    int val3 = find3(node , reqx);
                    int val = n + 1;
                    if(val1 != -1){
                        val = min(val , val1);
                    }
                    if(val2 != -1){
                        val = min(val , val2);
                    }
                    if(val3 != -1){
                        val = min(val , val3);
                    }
                    if(val > n){
                        ok = 0;
                    }
                    else{
                        if(mxx - val > mid || whomn.first + val > mid){
                            ok = 0;
                        }
                    }
                }
            }
            if(ok){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans[node] = l;
    }
    else{
        int next = who.second;
        int l = 0;
        int r = n;
        while(l < r){
            int mid = l + r >> 1;
            bool ok = 1;
            if(smxx > mid){
                ok = 0;
            }
            else{
                if(mxx > mid){
                    auto val = s[next].lower_bound(mxx - mid);
                    if(val != s[next].end()){
                        int x = *val;
                        if(mxx - x > mid || whomn.first + x > mid){
                            ok = 0;
                        }
                    }
                    else{
                        ok = 0;
                    }
                }
            }
            if(ok){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans[node] = l;
    }
    if(mx != -1){
        s[node].swap(s[mx]);
    }
    for(int next : v[node]){
        if(next != mx){
            s[node].insert(s[next].cbegin() , s[next].cend());
        }
    }
    s[node].insert(subtree[node]);
    --siz;
}
int main(){
    pre();
    scanf("%d" , &n);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
    }
    start = v[0][0];
    timer = 0;
    dfs(start);
    for(int i = 1 ; i <= n ; ++i){
        in[tin[i]].emplace_back(i);
        out[tout[i]].emplace_back(i);
    }
    root1[0] = dummy;
    for(int i = 1 ; i <= n ; ++i){
        root1[i] = root1[i - 1];
        for(int node : out[i]){
            insert(root1[i] , root1[i] , 1 , n , subtree[node]);
        }
    }
    root2[n + 1] = dummy;
    for(int i = n ; i >= 1 ; --i){
        root2[i] = root2[i + 1];
        for(int node : in[i]){
            insert(root2[i] , root2[i] , 1 , n , subtree[node]);
        }
    }
    siz = 0;
    dfs2(start , 0);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , ans[i] , " \n"[i == n]);    
    }
}