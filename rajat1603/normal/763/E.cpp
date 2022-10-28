#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 5e5 + 5;
const int SQN = 775;
struct query{
    int l;
    int r;
    int idx;
    query(int _l = 0, int _r = 0, int _idx = 0){
        l = _l;
        r = _r;
        idx = _idx;
    }
    bool operator < (const query &b) const {
        return r < b.r;
    }
};
struct DSU{
    int n;
    int parent[N];
    int rank[N];
    int groups;
    stack < int > buffer;
    DSU(int _n){
        n = _n;
        groups = _n;
        for(int i = 1 ; i <= _n ; ++i){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return find(parent[node]);
    }
    void join(int a , int b , bool roll){
        int x = find(a);
        int y = find(b);
        if(x == y){
            return;
        }
        groups--;
        if(rank[x] > rank[y]){
            parent[y] = x;
            if(roll){
                buffer.push(y);
            }
        }
        else if(rank[x] < rank[y]){
            parent[x] = y;
            if(roll){
                buffer.push(x);
            }
        }
        else{
            rank[x]++;
            parent[y] = x;
            if(roll){
                buffer.push(y);
                buffer.push(-x);
            }
        }
    }
    void rollback(){
        while(!buffer.empty()){
            int node = buffer.top();
            buffer.pop();
            if(node < 0){
                rank[-node]--;
            }
            else{
                parent[node] = node;
                groups++;
            }
        }
    }
};
int n , m , q;
pair < int , int > arr[M];
vector < int > vvv[N];
int lll[N] , rrr[N];
vector < query > v[SQN];
int ans[N];
int fst[N];
int parent[N];
int findd(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findd(parent[node]);
}
void brute(int idx){
    int l = lll[idx];
    int r = rrr[idx];
    for(int i = l ; i <= r ; ++i){
        parent[i] = i;
    }
    int ans = r - l + 1;
    for(int node = l ; node <= r ; ++node){
        for(int next : vvv[node]){
            if(next <= r){
                if(findd(node) != findd(next)){
                    parent[findd(next)] = findd(node);
                    --ans;
                }
            }
        }
    }
    ::ans[idx] = ans;
}
void brute2(int idx){
    int l = lll[idx];
    int r = rrr[idx];
    int ans = r - l + 1;
    for(int i = max(l , r - 10) ; i <= min(n , r + 10) ;  ++i){
        parent[i] = i;
    }
    for(int i = max(l , r - 10) ; i <= r ; ++i){
        for(int j : vvv[i]){
            if(i >= l && i <= r && j >= l && j <= r){
                if(findd(j) != findd(i)){
                    parent[findd(j)] = findd(i);
                    --ans;
                }
            }
        }
    }
    ::ans[idx] = ans;
}
int main(){
    scanf("%d %d" , &n , &m);
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
        if(arr[i].first > arr[i].second){
            swap(arr[i].first , arr[i].second);
        }
        vvv[arr[i].first].emplace_back(arr[i].second);
    }
    sort(arr + 1 , arr + 1 + m);
    for(int i = 1 ; i <= n ; ++i){
        fst[i] = m + 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        if(fst[arr[i].first] == m + 1){
            fst[arr[i].first] = i;
        }
    }
    for(int i = n - 1 ; i >= 1 ; --i){
        if(fst[i] == m + 1){
            fst[i] = fst[i + 1];
        }
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , lll + i , rrr + i);
        if(rrr[i] - lll[i] < 20){
            brute(i);
        }
        else{
            int l = fst[lll[i]];
            int r = fst[rrr[i] - 4] - 1;
            if(l <= r){
                v[l / SQN].emplace_back(query(l , r , i));
            }
            else{
                brute2(i);
            }
        }
    }
    for(int i = 0 ; i < SQN ; ++i){
        if(v[i].empty()){
            continue;
        }
        sort(v[i].begin() , v[i].end());
        int mxl = 0;
        for(int j = 0 ; j < v[i].size() ; ++j){
            mxl = max(mxl , v[i][j].l);
        }
        DSU dsu(n);
        for(int j = 0 ; j < v[i].size() ; ++j){
            if(v[i][j].r <= mxl){
                for(int k = v[i][j].l ; k <= v[i][j].r ; ++k){
                    dsu.join(arr[k].first , arr[k].second , 1);
                }
                for(int k = rrr[v[i][j].idx] - 6 ; k <= rrr[v[i][j].idx] ; ++k){
                    if(k >= lll[v[i][j].idx] && k <= rrr[v[i][j].idx]){
                        for(int next : vvv[k]){
                            if(next >= lll[v[i][j].idx] && next <= rrr[v[i][j].idx]){
                                dsu.join(k , next , 1);
                            }
                        }
                    }
                }
                ans[v[i][j].idx] = dsu.groups - (lll[v[i][j].idx] - 1 + n - rrr[v[i][j].idx]);
                dsu.rollback();
            }
            else{
                break;
            }
        }
        int curr = mxl;
        dsu.join(arr[mxl].first , arr[mxl].second , 0);
        for(int j = 0 ; j < v[i].size() ; ++j){
            if(v[i][j].r > mxl){
                int l = v[i][j].l;
                int r = v[i][j].r;
                while(curr < r){
                    ++curr;
                    dsu.join(arr[curr].first , arr[curr].second , 0);
                }
                for(int k = mxl-1 ; k >= l ; --k){
                    dsu.join(arr[k].first , arr[k].second , 1);
                }
                for(int k = rrr[v[i][j].idx] - 6 ; k <= rrr[v[i][j].idx] ; ++k){
                    if(k >= lll[v[i][j].idx] && k <= rrr[v[i][j].idx]){
                        for(int next : vvv[k]){
                            if(next >= lll[v[i][j].idx] && next <= rrr[v[i][j].idx]){
                                dsu.join(k , next , 1);
                            }
                        }
                    }
                }
                ans[v[i][j].idx] = dsu.groups - (lll[v[i][j].idx] - 1 + n - rrr[v[i][j].idx]);
                dsu.rollback();
            }
        }
        v[i].clear();
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}