#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int vis[N];

int main(){
    int n;
    cin >> n;
    int sk;
    for(int j = 1;j<=n;j++){
        cin >> sk;
        vis[sk] = j;
    }
    int ans = INT_MAX,l = 0;
    for(int j = 0;j<N;j++){
        if(vis[j]!=0)
            if(vis[j]<ans)
                ans = vis[j],l = j;
    }
    cout << l;
    return 0;
}