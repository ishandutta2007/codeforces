#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool prime[1010];
vector<int> p;
struct NODE{
    vector<int> op;
    int idx;
    bool operator<(const NODE &N)const{
        if (op.size()==N.op.size()){
            for (int i=0;i<(int)op.size();i++) if (op[i]!=N.op[i]) return op[i]<N.op[i];
            return idx<N.idx;
        }
        return op.size()<N.op.size();
    }
}a[300300];
int val[300300];

void factorize(int x){
    for (auto &d:p){
        int cnt=0;
        while(val[x]%d==0){
            cnt++;
            val[x] /= d;
        }
        if (cnt&1) a[x].op.push_back(d);
    }
    if (val[x]!=1) a[x].op.push_back(val[x]);
}

bool sm(int x, int y){
    if (a[x].op.size()!=a[y].op.size()) return false;
    for (int i=0;i<(int)a[x].op.size();i++) if (a[x].op[i]!=a[y].op[i]) return false;
    return true;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", val+i);
        a[i].idx = i;
        factorize(i);
    }
    sort(a, a+n);
    int mx0 = 0, mx1 = 0, idx=0, cur=1;
    for (;idx<n;idx++){
        if (a[idx].op.empty()) mx0++, mx1++;
        else break;
    }
    for (idx++;idx<n;idx++){
        if (sm(idx-1, idx)) cur++;
        else{
            mx0 = max(mx0, cur);
            if (cur%2==0) mx1 += cur;
            cur=1;
        }
    }
    mx0 = max(mx0, cur);
    if (cur%2==0) mx1 += cur;
    mx1 = max(mx1, mx0);
    int q;
    scanf("%d", &q);
    while(q--){
        ll w;
        scanf("%lld", &w);
        if (w) printf("%d\n", mx1);
        else printf("%d\n", mx0);
    }
    for (int i=0;i<n;i++) a[i].op.clear();
}

int main(){
    int t;
    scanf("%d", &t);
    fill(prime+2, prime+1010, 1);
    for (int i=2;i<1010;i++){
        if (!prime[i]) continue;
        p.push_back(i);
        for (int j=2;i*j<1010;j++) prime[i*j] = 0;
    }
    while(t--){
        solve();
    }
    return 0;
}