#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn];
int n;
int st[maxn], tp;
int pre[maxn], suf[maxn];
int L[maxn], R[maxn];
void init(){
    scanf("%d", &n);
    fors(i,1,n+1) scanf("%d", &a[i]);
    a[n+1] = 0;

    tp = 0;
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        while(tp > 0 && a[st[tp-1]] >= a[i]) tp--;
        if(tp) L[i] = st[tp-1];
        else L[i] = 0;
        st[tp++] = i;
        pre[i] = max(pre[i-1], a[i]);
    }

    suf[n+1] = 0;
    tp = 0;
    for(int i = n; i > 0; --i){
        while(tp > 0 && a[st[tp-1]] >= a[i]) tp--;
        if(tp) R[i] = st[tp-1];
        else R[i] = n+1;
        st[tp++] = i;
        suf[i] = max(a[i], suf[i+1]);
    }
}
void sol(){
    int x, y;
    for(int i = 2; i < n; ++i){
        if(L[i] == 0){
            if(a[1] == a[i]){
                x = 1;
            }else continue;
        }else{
            if(pre[L[i]] == a[i]){
                x = L[i];
            }else if(L[i]+1 < i && pre[L[i]+1] == a[i]){
                x = L[i]+1;
            }else continue;
        }
        //cout<<"i:"<<i<<" x:"<<x<<" r:"<<suf[R[i]]<<endl;
        if(R[i] == n+1){
            if(a[n] == a[i]){
                y = n;
            }else continue;
        }else{
            if(suf[R[i]] == a[i]){
                y = R[i];
            }else if(R[i]-1 > i && suf[R[i]-1] == a[i]){
                y = R[i]-1;
            }else continue;
        }
        printf("YES\n%d %d %d\n", x, y-1-x, n-y+1);
        return;
    }
    printf("NO\n");
    return;
}
int main()
{
    int T; cin>>T;
    while(T--){
        init();
        sol();
    }
}
/*
9
5 5 2 94 54 5 5 4 4
*/