#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
inline int scan(){
    int x=0;
    char c = getchar();
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x = (x<<3) + (x<<1) + c - '0';
        c=getchar();
    }
    return x;
}
const int N = 100001;
const int SQN = 340;
struct query{
    int l;
    int r;
    int val;
    int index;
};
bool compare (query &a , query &b){
    if((a.l/SQN) != (b.l/SQN)){
        return a.l < b.l;
    }
    return a.r < b.r;
}
int answer[N];
int cnt[N]={0};
int cur[N]={0};
int arr[N];
int start[N];
int finish[N];
int col[N];
list<int> v[N];
query Q[N];
int timer=0;
int n,m;
void dfs(int node,int parent){
    start[node]=++timer;
    arr[timer]=col[node];
    for(list<int>::iterator it = v[node].begin();it!=v[node].end();++it){
        if(*it!=parent){
            dfs(*it,node);
        }
    }
    finish[node]=timer;
}
int main(){
    n=scan(),m=scan();
    for(int i=1;i<=n;++i){
        col[i]=scan();
    }
    for(int i=1;i<n;++i){
        int a=scan(),b=scan();
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1,-1);
    for(int i=1;i<=m;++i){
        int node=scan(),val=scan();
        Q[i].l =start[node];
        Q[i].r =finish[node];
        Q[i].val=val;
        Q[i].index=i;
    }
    sort(Q+1,Q+1+m,compare);
    int curl=1,curr=0;
    for(int i=1;i<=m;++i){
        int l = Q[i].l;
        int r = Q[i].r;
        while(curl>l){
            --curl;
            cnt[arr[curl]]++;
            cur[cnt[arr[curl]]]++;
        }
        while(curr<r){
            ++curr;
            cnt[arr[curr]]++;
            cur[cnt[arr[curr]]]++;
        }
        while(l>curl){
            cnt[arr[curl]]--;
            cur[cnt[arr[curl]]+1]--;
            curl++;
        }
        while(r<curr){
            cnt[arr[curr]]--;
            cur[cnt[arr[curr]]+1]--;
            curr--;
        }
        answer[Q[i].index]=cur[Q[i].val];
    }
    for(int i=1;i<=m;++i){
        printf("%d\n",answer[i]);
    }
}