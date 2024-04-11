#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<string> a;
vector<int> v, S;
//vector<int> dp;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    v.resize(m, 0);
    S.resize(m, 0);
    //dp.resize(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        //dp[i].resize(m);
    }

    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if (a[i-1][j]=='X' && a[i][j-1]=='X') v[j] = 1;
        }
    }

    S[0] = v[0];
    for (int i=1;i<m;i++) S[i] = S[i-1]+v[i];

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if (x==y) {printf("YES\n"); continue;}
        if (S[y-1]!=S[x-1]) printf("NO\n");
        else printf("YES\n");
    }

    /*for (int i=0;i<n;i++){
        if (a[i]=='.') dp[i][j] = 1;
        else dp[i][j] = 0;
    }
    for (int j=0;j<m;j++){
        if (a[i]=='.') dp[i][j] = 1;
        else dp[i][j] = 0;
    }

    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if ((dp[i-1][j] || dp[i][j-1]) && a[i][j]=='.') dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }*/
    return 0;
}