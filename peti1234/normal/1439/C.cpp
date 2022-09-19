#include <bits/stdc++.h>

using namespace std;
const int c=524288, k=c/2;
int n, q, kezd[c], veg[c], lazy[c], maxi[c], mini[c];
long long sum[c], s, ans;
void ladd(int pos, long long val) {
    lazy[pos]=val, mini[pos]=val, maxi[pos]=val;
    sum[pos]=val*(veg[pos]-kezd[pos]+1);
}
void shift(int a) {
    int x=lazy[a];
    if (x) {
        ladd(2*a, x), ladd(2*a+1, x);
        lazy[a]=0;
    }
}
void upd(int a) {
    sum[a]=sum[2*a]+sum[2*a+1];
    maxi[a]=maxi[2*a], mini[a]=mini[2*a+1];
}
void maximize(int a, int pos, int val) {
    if (pos<kezd[a] || val<=mini[a]) return;
    if (pos>=veg[a] && val>=maxi[a]) {
        ladd(a, val);
        return;
    }
    shift(a);
    maximize(2*a, pos, val), maximize(2*a+1, pos, val);
    upd(a);
}
long long pre_sum(int a, int pos) {
    if (kezd[a]>pos) return 0;
    if (veg[a]<=pos) return sum[a];
    shift(a);
    return pre_sum(2*a, pos)+pre_sum(2*a+1, pos);
}
int bs1(int a, int pos, int val) {
    if (veg[a]<pos || mini[a]>val) return veg[a]+1;
    if (a>=k) return kezd[a];
    shift(a);
    int x=bs1(2*a, pos, val);
    if (x>veg[2*a]) x=bs1(2*a+1, pos, val);
    return x;
}
int bs2(int a) {
    int db=veg[a]-kezd[a]+1;
    if (kezd[a]>n || mini[a]>s) return 0;
    if (veg[a]<=n && s>=sum[a]) {
        s-=sum[a];
        return db;
    }
    shift(a);
    if (veg[2*a]>n || s<sum[2*a]) return bs2(2*a);
    s-=sum[2*a];
    return db/2+bs2(2*a+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=k; i<c; i++) kezd[i]=i-k+1, veg[i]=i-k+1;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        ladd(i+k-1, x);
    }
    for (int i=k-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
        upd(i);
    }
    for (int i=1; i<=q; i++) {
        long long q, pos, val;
        cin >> q >> pos >> val;
        if (q==1) {
            maximize(1, pos, val);
        } else {
            ans=0, s=val;
            while(pos<=n) {
                pos=bs1(1, pos, s);
                s+=pre_sum(1, pos-1);
                int new_pos=bs2(1)+1;
                ans+=new_pos-pos, pos=new_pos;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}