#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
ll exgcd(ll a,ll b,ll& x,ll &y){
	if(b==0) {
		x=1;y=0;
		return a;
	}
	ll x1,y1;
	ll ans=exgcd(b,a%b,x1,y1);
	x=y1;
	y=x1-a/b*y1;
	return ans;
}
struct node{
    int op;
    ll x, y;
};
vector<node> ans;
void add(ll x, ll y){ans.pb((node){0,x,y});}
void xorr(ll x, ll y){ans.pb((node){1,x,y});}
void show(){
    cout<<ans.size()<<endl;
    fors(i,0,ans.size()){
        if(ans[i].op == 0) printf("%lld + %lld\n", ans[i].x, ans[i].y);
        else printf("%lld ^ %lld\n", ans[i].x, ans[i].y);
    }
}
vector<ll> p;
void pre(ll x){
    fors(i,0,14) add(x, x), x += x; return;
}
void kx(ll k, ll x){
    vector<ll> ned; ned.clear();
    while(k){
        if(k&1) ned.pb(x);
        x <<= 1;
        k >>= 1;
    }
    if(ned.size() > 1){
        x = ned[0];
        fors(i,1,ned.size()){
            add(x, ned[i]);
            x += ned[i];
        }
    }
    return;
}
void sol(ll x){
    int flag = 0;
    p.clear();
    ll a, b;
    while(!flag){
        ans.clear();
        xorr(x, x);
        pre(x);
        //cout<<"?"<<endl;
        p.clear();
        for(int l = 1; l <= 50; ++l){
            int t = rand()%711;
            int g = rand()%891;
            kx(t, x);
            kx(g, x);
            ll r = (t*x)^(g*x);
            //printf("%lld ^ %lld\n", t*x, g*x);
            xorr(t*x, g*x);
            p.pb(r);
        }
        //cout<<"?1:"<<endl;
        int len = p.size();
        fors(i,0,len){
            ll y = p[i];
            pre(y);
            for(int l = 1; l <= 50; ++l){
                int t = rand()%911;
                int g = rand()%371;
                kx(t, y);
                kx(g, y);
                ll r = (t*y)^(g*y);
                //printf("%lld ^ %lld\n", t*y, g*y);
                xorr(t*y, g*y);
                p.pb(r);
            }
        }
        //cout<<"?2:"<<endl;
        sort(p.begin(), p.end());
        a = x;
        fors(i,0,p.size()){
            b = p[i];
            if(__gcd(a, b) == 1){
                flag = 1; break;
            }
        }
    }
    //cout<<"!:"<<endl;
    //cout<<"?"<<endl;
    ll x0, y0;
    //cout<<"a:"<<a<<" b:"<<b<<endl;
    exgcd(a, b, x0, y0);
    x0 %= b;
    x0 += b;
    x0 %= b;
    y0 = (a*x0-1)/b;
    if(y0%2 == 1) y0 += a, x0 += b;
    //cout<<"x0:"<<x0<<" y0:"<<y0<<endl;
    //x0 * a = y0 * b + 1

    ll cur = a;
    ll k = x0;
    ll res = 0;
    while(k){
        if(k&1) add(res, cur), res += cur;
        add(cur, cur);
        cur += cur;
        k >>= 1;
    }

    res = 0;
    k = y0;
    cur = b;
    while(k){
        if(k&1) add(res, cur), res += cur;
        add(cur, cur);
        cur += cur;
        k >>= 1;
    }
    //printf("%lld ^ %lld\n", x0*a, y0*b);
    xorr(x0*a, y0*b);
    //cout<<"x0*a:"<<x0*a<<" y0*b:"<<y0*b<<endl;
    show();
    return;
}
/*
262145
392829
524289
*/
int main()
{

//    ll x;
//    srand(time(0));
//    for(int i = 392829; i < 392829+2; i += 2){
//        if(i%1000 == 1) cout<<"cur:"<<i<<endl;
//        x = i;
//        int flag = 0;
//        p.clear();
//        for(int l = 1; l <= 50; ++l){
//            int t = rand()%711;
//            int g = rand()%891;
//            ll r = (t*x)^(g*x);
//            p.pb(r);
//        }
//        for(ll y: p){
//            for(int l = 1; l <= 50; ++l){
//                int t = rand()%911;
//                int g = rand()%371;
//                ll r = (t*y)^(g*y);
//                p.pb(r);
//            }
//        }
//        sort(p.begin(), p.end());
//        int st = 0;
//        if(p.size() > 200) st = max(st, (int)(rand()%(p.size()-100)) );
//        for(int i = st; i < min((int)p.size(),st+100); ++i){
////            for(int j = i+1; j < min((int)p.size(),i+100); ++j){
////                if(__gcd(p[i], p[j]) == 1){
////                    flag = 1;
////                    cout<<"a:"<<p[i]<<" b:"<<p[j]<<endl;
////                    break;
////                }if(flag) break;
////            }if(flag) break;
//            if(__gcd(x, p[i]) == 1){
//                //cout<<"a:"<<x<<" b:"<<p[i]<<endl;
//                flag = 1; break;
//            }
//        }
//        if(flag == 0) cout<<"i:"<<i<<endl;
//    }
    ll x; scanf("%lld", &x);
    //scanf("%lld", &x);
    sol(x);
//    scanf("%lld", &x);
//    ll cur = x;
//    for(int i = 0; i <= 20; ++){
//        printf("%lld + %lld", cur);
//        cur <<= 1;
//    }
//    for(int l = 1; l <= 100; ++l){
//        ll a = rand()%1000+1;
//        for(int r = 1; r <= 100; ++r){
//
//        }
//    }
}