#include <bits/stdc++.h>
using namespace std;

int a[200000];
int b[200000];
int c[200000];
vector<int> adj[200000];
const long long bil=1000000000;
int cnt=0;
int save[200000];
typedef pair<int,int> P;
int zero[200000];
int one[200000];

void makeval(int v,int par,int val) {
    val=min(val,a[v]);
    save[v]=val;
    if (b[v]!=c[v]) {
        if (c[v]==0) {
            zero[v]=1;
        }
        else {
            one[v]=1;
        }
    }
    for(int i=0;i<adj[v].size();i++) {
        int next=adj[v][i];
        if (next!=par) {
            makeval(next,v,val);
            zero[v]+=zero[next];
            one[v]+=one[next];
        }
    }
}

long long solve(int v,int prev) {
    int sum0=0;
    int sum1=0;
    long long ret=0;
    for(int i=0;i<adj[v].size();i++) {
        int next=adj[v][i];
        if (next!=prev) {
            ret+=solve(next,v);
            if (zero[next]>one[next]) {
                sum0+=zero[next]-one[next];
            }
            else {
                sum1+=one[next]-zero[next];
            }
        }
    }
    if (b[v]!=c[v]) {
        if (c[v]==0) {
            sum0++;
        }
        else {
            sum1++;
        }
    }
    ret+=2LL*min(sum0,sum1)*save[v];
    return ret;
}

int main(void) {
    int n;
    scanf("%d",&n);
    int bsum=0;
    int csum=0;
    for(int i=0;i<n;i++) {
        scanf("%d %d %d\n",&a[i],&b[i],&c[i]);
        bsum+=b[i];
        csum+=c[i];
    }
    if (bsum!=csum) {
        printf("-1");
        return 0;
    }
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeval(0,-1,bil);
    printf("%lld",solve(0,-1));
}