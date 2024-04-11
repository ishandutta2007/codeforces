#include <bits/stdc++.h>
using namespace std;
#define ll long long

char str[110];

int main() {
    int n,m;
    scanf("%d",&n);
    set<int> s;
    map<int,int> mp;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        s.insert(a);
        mp[a] = max(mp[a],b);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        s.insert(a);
        mp[a] = max(mp[a],b);
    }
    for(set<int> :: iterator it = s.begin(); it != s.end(); it++)
        ans += mp[*it];
    printf("%lld\n",ans);
}