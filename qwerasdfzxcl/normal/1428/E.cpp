#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100100], pt[100100];
struct Node{
    ll x;
    int y;
    Node(){}
    Node(ll _x, int _y): x(_x), y(_y) {}
    bool operator<(const Node &N) const{
        if (x==N.x) return y<N.y;
        return x<N.x;
    }
};

ll calc(int x, int y){
    ll c = a[x]/y, d = a[x]%y;
    return c*c*(y-d)+(c+1)*(c+1)*d;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    ll ans = 0;
    priority_queue<Node> pq;
    fill(pt, pt+n, 1);
    for (int i=0;i<n;i++){
        ans += (ll)a[i]*a[i];
        if (a[i]<=pt[i]) continue;
        pq.push(Node(calc(i, pt[i])-calc(i, pt[i]+1), i));
        pt[i]++;
    }
    for (int i=0;i<k-n;i++){
        auto cur = pq.top(); pq.pop();
        ans -= cur.x;
        if (a[cur.y]<=pt[cur.y]) continue;
        pq.push(Node(calc(cur.y, pt[cur.y])-calc(cur.y, pt[cur.y]+1), cur.y));
        pt[cur.y]++;
    }
    printf("%lld\n", ans);
    return 0;
}