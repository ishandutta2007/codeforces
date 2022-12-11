#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int>ch;
    int s;
    for(int j = 0;j<n;j++){
        cin >> s;
        if(s==1)ch.push_back(j);
    }
    if(ch.size()==0){
        cout << 0;
        exit(0);
    }
    ll ans = 1;
    for(int x = 1;x<ch.size();x++){
        ans *= ch[x]-ch[x-1];
    }
    cout << ans;
    return 0;
}