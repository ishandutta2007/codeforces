#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e7 + 50;
int h[maxn];
int p[maxn];
int cnt = 0;
vector<ll> v;
int vis[maxn];
int main()
{
    for(int i = 4; i < maxn; i += 2) h[i] = 1;
    for(int i = 3; i * i < maxn; i += 2){
        if(!h[i]){
            for(int j = i*i; j < maxn; j += 2*i){
                h[j] = 1;
            }
        }
    }
    for(int i = 2; i < maxn; ++i) if(!h[i]) p[cnt++] = i;
    ll n; cin>>n;
    if(n == 1){
        cout<<1<<endl; return 0;
    }
    v.clear();
    for(int i = 0; i < cnt; ++i){
        if(n%p[i] == 0){
            v.push_back(p[i]);
            while(n%p[i] == 0) n/= p[i];
        }
    }
    if(n!=1) v.push_back(n);

    if(v.size() == 1){
        cout<<v[0]<<endl;
    }
    else{
        cout<<1<<endl;
    }
}