#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pair<int,int> pii
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);

void Solve(){
    int n;
    cin >> n;
    int l,r;
    int cur = 1;
    int tea[n];
    for(int i = 0;i<n;i++)tea[i]=0;
    for(int i = 0;i<n;i++){
        cin >> l >> r;
        cur=max(cur,l);
        if(cur>r)continue;
        tea[i]=cur;
        cur++;
    }
    for(int i = 0;i<n;i++)cout << tea[i] << " ";
    cout << "\n";
}

int main(){
    fastIO;
    int q;
    cin >> q;
    while(q--)
        Solve();
    return 0;
}