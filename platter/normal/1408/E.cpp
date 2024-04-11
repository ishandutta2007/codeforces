#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int a[100000];
int b[100000];
typedef pair<int,P> Pi;
vector<Pi> edge;
int p[200000];

int find(int a) {
    if (p[a]<0) {
        return a;
    }
    return p[a]=find(p[a]);
}

void merge(int a,int b) {
    a=find(a);
    b=find(b);
    if (a==b) {
        return;
    }
    p[b]=a;
}

int main(void) {
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&b[i]);
    }
    long long ret=0;
    for(int i=0;i<m;i++) {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            int x;
            scanf("%d",&x);
            x--;
            edge.push_back(Pi(b[x]+a[i],P(x,i+n)));
            ret+=b[x]+a[i];
        }
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    memset(p,-1,sizeof(p));
    for(int i=0;i<edge.size();i++) {
        if (find(edge[i].second.first)!=find(edge[i].second.second)) {
            merge(edge[i].second.first,edge[i].second.second);
            ret-=edge[i].first;
        }
    }
    printf("%lld",ret);
}