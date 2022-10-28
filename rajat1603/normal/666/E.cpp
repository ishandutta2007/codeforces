#include "bits/stdc++.h"
using namespace std;
const int N = 6e5 + 5;
const int SQN = 650;
const int LN = 20;
const int SN = 1 << 18;
int n;
char str[N];
char inp[N];
int belong[N];
int sa[LN + 1][N];
int finalsa[N];
int lcp[N];
int st[LN][N];
int logtable[N];
pair < int , int > tmp[N];
int head1[N];
int next1[N];
int head2[N];
int next2[N];
void build(){
       for(int i = 1 ; i <= n ; ++i){
        sa[0][i] = max(1 , str[i] - 'a' + 2);
    }
    tmp[0] = make_pair(-2 , -2);
    for(int lg = 1 ; lg <= LN ; ++lg){
        int mx1 = 0;
        int mx2 = 0;
        for(int i = 1 ; i <= n ; ++i){
            int x = i + (1 << (lg - 1));
            tmp[i] = make_pair(sa[lg - 1][i] , (x <= n) ? sa[lg - 1][x] : 0);
            mx1 = max(mx1 , tmp[i].second);
            mx2 = max(mx2 , tmp[i].first);
        }
        for(int i = 0 ; i <= mx1 ; ++i){
            head1[i] = 0;
        }
        for(int i = 1 ; i <= n ; ++i){
            int x = tmp[i].second;
            next1[i] = head1[x];
            head1[x] = i;
        }
        for(int i = 0 ; i <= mx2 ; ++i){
            head2[i] = 0;
        }
        for(int i = mx1 ; i >= 0 ; --i){
            for(int idx = head1[i] ; idx ; idx = next1[idx]){
                int x = tmp[idx].first;
                next2[idx] = head2[x];
                head2[x] = idx;
            }
        }
        int last = 0;
        int cur = 0;
        for(int i = 0 ; i <= mx2 ; ++i){
            for(int idx = head2[i] ; idx ; idx = next2[idx]){
                cur += tmp[last] != tmp[idx];
                sa[lg][idx] = cur;
                last = idx;      
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        finalsa[sa[LN][i]] = i;
    }
    for(int i = 1 ; i < n ; ++i){
        lcp[i] = 0;
        int x = finalsa[i];
        int y = finalsa[i + 1];
        for(int j = LN ; j >= 0 ; --j){
            if(sa[j][x] == sa[j][y]){
                lcp[i] += 1 << j;
                x += 1 << j;
                y += 1 << j;
            }
        }
    }
    lcp[n] = 0;
}
void sparse(){
    for(int i = 1 ; i <= n ; ++i){
        st[0][i] = lcp[i];
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
            st[i][j] = min(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
        }
    }
    logtable[0] = -1;
    logtable[1] = 0;
    for(int i = 2 ; i <= n ; ++i){
        logtable[i] = logtable[i >> 1] + 1;
    }
}
int query(int l , int r){
    if(r > n){
        return 0;
    }
    if(r < l){
        return N;
    }
    int k = logtable[r - l + 1];
    return min(st[k][l] , st[k][r - (1 << k) + 1]);
}
int m;
int q;
int aa[N] , bb[N] , cc[N] , dd[N];
vector < pair < int , int > > v[N];
int indd[N];
int ql[N];
int qr[N];
struct queryb{
    int l , r;
    int idx;
    queryb(int _l = 0 , int _r = 0 , int _idx = 0){
        l = _l;
        r = _r;
        idx = _idx;
    }
    bool operator < (const queryb &o) const {
        if(int(l / SQN) == int(o.l / SQN)){
            return r < o.r;
        }
        return l < o.l;
    }
};
queryb arrr[N];
int curl = 1 , curr = 0;
pair < int , int > ans[N];
pair < int , int > segtree[SN];
void builds(int l , int r , int node){
    segtree[node] = make_pair(0 , -l);
    if(l < r){
        int mid = l + r >> 1;
        builds(l , mid , node + node);
        builds(mid + 1 , r , node + node + 1);
    }
}
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree[node].first += val;
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx , val);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx , val);
        }
        segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
    }
}
pair < int , int > query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return make_pair(-1 , -1);
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return max(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
void add(int idx){
    idx = finalsa[idx];
    if(belong[idx] > 0){
        update(1 , m , 1 , belong[idx] , 1);
    }
}
void remove(int idx){
    idx = finalsa[idx];
    if(belong[idx] > 0){
        update(1 , m , 1 , belong[idx] , -1);
    }
}
int main(){
    scanf("%s" , inp + 1);
    n = 0;
    for(int i = 1 ; inp[i] ; ++i){
        str[++n] = inp[i];
        belong[n] = 0;
        indd[n] = i;
    }
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%s" , inp + 1);
        str[++n] = '$';
        belong[n] = -1;
        for(int j = 1 ; inp[j] ; ++j){
            str[++n] = inp[j];
            belong[n] = i;
        }
    }
    build();
    sparse();
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d %d %d" , aa + i , bb + i , cc + i , dd + i);
        v[cc[i]].emplace_back(make_pair(dd[i] - cc[i] + 1 , i));
    }
    for(int i = 1 ; i <= n ; ++i){
        int idx = finalsa[i];
        if(belong[idx] == 0){
            for(auto it : v[idx]){
                int sz = it.first;
                int l = 1;
                int r = i;
                while(l < r){
                    int mid = l + r >> 1;
                    if(query(mid , i - 1) >= sz){
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                ql[it.second] = l;
                l = i + 1;
                r = n + 1;
                while(l < r){
                    int mid = l + r >> 1;
                    if(query(i , mid - 1) < sz){
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                qr[it.second] = r - 1;
            }
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        arrr[i] = queryb(ql[i] , qr[i] , i);
    }
    sort(arrr + 1 , arrr + 1 + q);
    builds(1 , m , 1);
    for(int i = 1 ; i <= q ; ++i){
        while(curr < arrr[i].r){
            add(++curr);
        }
        while(curl > arrr[i].l){
            add(--curl);
        }
        while(curr > arrr[i].r){
            remove(curr--);
        }
        while(curl < arrr[i].l){
            remove(curl++);
        }
        ans[arrr[i].idx] = query(1 , m , 1 , aa[arrr[i].idx] , bb[arrr[i].idx]);
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d %d\n" , -ans[i].second , ans[i].first);
    }
}