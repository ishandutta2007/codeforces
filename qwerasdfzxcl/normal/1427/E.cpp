#include <bits/stdc++.h>
#define ll unsigned long long
#define lll long long

using namespace std;
vector<pair<ll, ll>> ans;
vector<int> op;

pair<lll, lll> ex_euclid(lll x, lll y){
    if (x==0) return make_pair(0, -1);
    pair<lll, lll> ret=ex_euclid(y%x, x);
    ret.second=-ret.first;
    ret.first=((lll)1+y*ret.second)/x;
    while(ret.first>=0 && ret.second>=0){
        ret.first -= y;
        ret.second -= x;
    }
    while(ret.first<0 || ret.second<0){
        ret.first += y;
        ret.second += x;
    }
    //printf("%lld %lld: %lld %lld\n", x, y, ret.first, ret.second);
    return ret;
}

void solve(){
    printf("%d\n", (int)ans.size());
    for (int i=0;i<(int)ans.size();i++){
        if (op[i]==1){
            printf("%llu + %llu\n", ans[i].first, ans[i].second);
        }
        else printf("%llu ^ %llu\n", ans[i].first, ans[i].second);
    }
}

int main(){
    ll x;
    scanf("%llu", &x);
    if (x&2){
        ans.push_back(make_pair(x, x));
        ans.push_back(make_pair(x, x*2));
        op.push_back(1);
        op.push_back(2);
        x=x^(x*2);
    }
    int idx;
    for (idx=30;idx>=0;idx--) if (x&((ll)1<<idx)) break;
    ll tmp=x;
    for (int i=1;i<=idx;i++){
        ans.push_back(make_pair(tmp, tmp));
        op.push_back(1);
        tmp <<= 1;
    }
    ll tmp1=tmp+x, tmp2=tmp^x;
    ans.push_back(make_pair(tmp, x));
    ans.push_back(make_pair(tmp, x));
    ans.push_back(make_pair(tmp1, tmp2));
    op.push_back(1);
    op.push_back(2);
    op.push_back(2);
    ll y=tmp1^tmp2;
    //printf("x, y: %lld %lld\n", x, y);
    pair<lll, lll> rrans=ex_euclid(x, y); ///ax-by=1 solution
    pair<ll, ll> rans;
    rans.first=rrans.first;
    rans.second=rrans.second;
    //printf("a, b: %lld %lld\n", rans.first, rans.second);
    vector<int> bita, bitb;
    for (int i=63;i>=0;i--){
        if (rans.first&((ll)1<<i)) bita.push_back(i);
        if (rans.second&((ll)1<<i)) bitb.push_back(i);
    }
    vector<ll> tmpa, tmpb;
    tmpa.push_back(x); tmpb.push_back(y);
    ll curx=x, cury=y;
    for (int i=1;i<=bita[0];i++){
        ans.push_back(make_pair(curx, curx));
        op.push_back(1);
        curx <<= 1;
        tmpa.push_back(curx);
    }
    for (int i=1;i<=bitb[0];i++){
        ans.push_back(make_pair(cury, cury));
        op.push_back(1);
        cury <<= 1;
        tmpb.push_back(cury);
    }
    ll cura=tmpa.back(), curb=tmpb.back();
    for (int i=1;i<(int)bita.size();i++){
        ans.push_back(make_pair(cura, tmpa[bita[i]]));
        op.push_back(1);
        cura += tmpa[bita[i]];
    }
    for (int i=1;i<(int)bitb.size();i++){
        ans.push_back(make_pair(curb, tmpb[bitb[i]]));
        op.push_back(1);
        curb += tmpb[bitb[i]];
    }
    assert(cura-curb==1);
    if(curb&1){
        ans.push_back(make_pair(curb, curb));
        ans.push_back(make_pair(curb, cura));
        op.push_back(1);
        op.push_back(1);
        curb=curb*2;
        cura=curb*2+1;
    }
    ans.push_back(make_pair(curb, cura));
    op.push_back(2);
    solve();
    return 0;
}