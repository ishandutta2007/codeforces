#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define ull unsigned long long
using namespace std;
const int maxn = 3e5 + 50;
const ull sed = 1e9 + 7;
int a[maxn], n;
int s[maxn], tp;
ull ha[maxn];
ll ans;
void init(){
    scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
map<ll,int> mp;
void sol(int l, int r){
    if(l >= r) return;
    sol(l, mid); sol(mid+1, r);
    mp.clear();
    tp = 0; ha[0] = 0;
    for(int i = mid+1; i <= r; ++i){
        if(tp && s[tp] == a[i]) tp--;
        else s[++tp] = a[i], ha[tp] = ha[tp-1]*sed + a[i];
        mp[ha[tp]]++;
    }
    tp = 0; ha[0] = 0;
    for(int i = mid; i >= l; --i){
        if(tp && s[tp] == a[i]) tp--;
        else s[++tp] = a[i], ha[tp] = ha[tp-1]*sed + a[i];
        ans += mp[ha[tp]];
    }return;
}
int main()
{
	int T; cin>>T;
	while(T--){
        init();
        ans = 0;
        sol(1, n);
        printf("%I64d\n", ans);
	}
}