#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

void open(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int cnt[105];
int main()
{
    //open();
    int n,x;
    cin >> n >> x;
    int v;
    for(int j = 0;j<n;j++){
        cin >> v;
        cnt[v]++;
    }
    int ans = cnt[x];
    for(int j = 0;j<x;j++){
        if(cnt[j] == 0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}