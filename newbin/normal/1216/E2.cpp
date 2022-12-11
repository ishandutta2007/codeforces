#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
ll p[20];
ll check1(ll lim){//1~lim
    ll sum = 0;
    ll cur = 0;
    ll cnt;
    ll len = 0;
    while(1){
        len++;
        if(p[len]-1 <= lim){
            cnt = p[len] - p[len-1];
            sum += cur*cnt + (cnt+1)*cnt/2*len;
            cur += cnt*len;
        }
        else{
            cnt = lim-p[len-1]+1;
            sum += cur*cnt + (cnt+1)*cnt/2*len;
            cur += cnt*len;
        }
        if(p[len]>lim) break;
    }
    return sum;
}
ll check2(ll lim){
    ll sum = 0;
    ll len = 0;
    while(1){
        len++;
        if(p[len]-1 <= lim){
            ll cnt = p[len] - p[len-1];
            sum += cnt*len;
        }
        else{
            ll cnt = lim+1-p[len-1];
            sum += cnt*len;
        }
        if(p[len] > lim) break;
    }return sum;
}
int main()
{
    p[0] = 1; for(int i = 1; i < 20; ++i) p[i] = p[i-1]*10;
	int T;cin>>T;
	while(T--){
        ll k; cin>>k;
        ll l = 0, r = 1e9;
        ll ans;
        while(l <= r){
            //cout<<"l:"<<l<<" r:"<<r<<endl;
            if(check1(mid) < k) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        k -= check1(ans);//
        ans++;//1~ans
        l = 0, r = ans;
        while(l <= r){
            if(check2(mid) < k) ans = mid, l = mid+1;
            else r = mid-1;
        }

        k -= check2(ans);
        ans++;
        cout<<to_string(ans)[k-1]<<endl;
	}
}