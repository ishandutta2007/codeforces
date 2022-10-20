#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int path[500500];
int h[500500];

int dis_find(int s){
    if(s==path[s]) return path[s];
    return path[s]=dis_find(path[s]);
}

int dis_merge(int s1, int s2){
    if (s2==-1) return 1;
    int v1=dis_find(s1), v2=dis_find(s2);
    if (v1==v2) return 0;
    if (h[v1]>h[v2]) swap(v1, v2);
    path[v1]=v2;
    if (h[v1]==h[v2]) h[v2]++;
    return 1;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=m;i++) path[i]=i;
    int tmp=-1;
    int ans=0;
    vector<int> pr;
    for (int i=0;i<n;i++){
        int k;
        scanf("%d", &k);
        if (k==1){
            int tmp2, tmp3;
            scanf("%d", &tmp2);
            tmp3=dis_merge(tmp2, tmp);
            tmp=tmp2;
            if (tmp3) pr.push_back(i+1);
            ans += tmp3;
        }
        else{
            int a, b, tmp2;
            scanf("%d %d", &a, &b);
            tmp2=dis_merge(a, b);
            if (tmp2) pr.push_back(i+1);
            ans += tmp2;
        }
    }
    ll rans=1, mod=1e9+7;
    for (int i=0;i<ans;i++) rans=(rans<<1)%mod;
    printf("%lld %d\n", rans, ans);
    for (int x:pr) printf("%d ", x);
    return 0;
}