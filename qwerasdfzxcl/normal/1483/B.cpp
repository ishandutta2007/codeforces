#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[100100], path[100100], n;
vector<int> ans, dlt, tmp_dlt;
bool chk[100100];

int add(int x, int y){
    int ret = x+y;
    if (ret>=n) return ret-n;
    else return ret;
}

int dis_find(int x){
    if (path[x]==x) return x;
    return path[x]=dis_find(path[x]);
}

void solve(){
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    ans.clear(); dlt.clear();
    for (int i=0;i<=n;i++){
        path[i]=i; chk[i]=0;
    }
    for (int i=0;i<n-1;i++){
        if (chk[i]) continue;
        int tmp = __gcd(a[i], a[i+1]);
        if (tmp!=1) continue;
        chk[i+1]=1;
        dlt.push_back(i);
        ans.push_back(i+1);
        path[i]=dis_find(i+1);
    }
    if (!chk[n-1]){
        int tmp = __gcd(a[n-1], a[0]);
        if (tmp==1){
            chk[0]=1;
            dlt.push_back(n-1);
            ans.push_back(0);
            path[n-1]=dis_find(0);
        }
    }
    while(!dlt.empty()){
        for (int t:dlt){
            if (chk[t]) continue;
            int tmp = __gcd(a[t], a[add(dis_find(t), 1)]);
            if (tmp!=1) continue;
            chk[add(dis_find(t), 1)]=1;
            tmp_dlt.push_back(t);
            ans.push_back(add(dis_find(t), 1));
            path[t]=dis_find(add(dis_find(t), 1));
        }
        dlt.clear();
        dlt=tmp_dlt;
        tmp_dlt.clear();
    }
    printf("%d ", (int)ans.size());
    for (int x:ans) printf("%d ", x+1);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}