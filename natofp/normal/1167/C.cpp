#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=5e5+5;
int parent[nax];
int roz[nax];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (roz[a] < roz[b])
            swap(a, b);
        parent[b] = a;
        roz[a] += roz[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        roz[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int k; cin>>k;
        if(k==0) continue;
        int glowny;
        cin>>glowny;
        for(int j=1;j<k;j++)
        {
            int x; cin>>x;
            union_sets(glowny,x);
        }
    }
    for(int i=1;i<=n;i++) cout<<roz[find_set(i)]<<" ";
    return 0;
}