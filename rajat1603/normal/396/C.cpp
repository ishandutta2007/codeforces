#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
const int N = 300001;
int b[N]={0};
int B[N]={0};
vector<int> v[N];
int start[N];
int finish[N];
int level[N];
int timer=0;
int n;
const int mod = 1e9+7;
void dfs(int node){
    start[node]=++timer;
    int x=v[node].size();
    for(int i=0;i<x;++i){
        level[v[node][i]]=level[node]+1;
        dfs(v[node][i]);
    }
    finish[node]=timer;
}
void update(int *bit,int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        bit[idx]%=mod;
        bit[idx]+=mod;
        bit[idx]%=mod;
        idx+=idx&-idx;
    }
}
int query(int *bit,int idx){
    int res=0;
    while(idx){
        res+=bit[idx];
        res%=mod;
        idx&=idx-1;
    }
    return res;
}
int main(){
    n=scan();
    for(int i=2;i<=n;++i){
        int p=scan();
        v[p].pb(i);
    }
    level[1]=0;
    dfs(1);
    int q=scan();
    while(q--){
        int type=scan();
        if(type==1){
            int node=scan(),x=scan(),k=scan();
            int addval=(x + (1LL*level[node]*k)%mod)%mod;
            update(b,start[node],addval);
            update(b,finish[node]+1,-addval);
            update(B,start[node],k);
            update(B,finish[node]+1,-k);
        }
        else{
            int node=scan();
            printf("%d\n",(query(b,start[node])-(1LL*level[node]*query(B,start[node]))%mod+mod)%mod);
        }
    }
}