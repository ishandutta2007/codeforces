#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int x[maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        ll x, y; cin>>x>>y;
        if(x == y+1) printf("NO\n");
        else printf("YES\n");
    }
}