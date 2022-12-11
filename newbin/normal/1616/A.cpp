#include<bits/stdc++.h>
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int n; scanf("%d", &n);
        map<int,int> a;
        while(n--){
            int x; cin>>x;
            if(x < 0) x = -x;
            a[x]++;
        }
        int ans = 0;
        for(auto p:a){
            int cnt = p.second;
            cnt = min(cnt, 2);
            if(p.first == 0) cnt = min(cnt, 1);
            ans += cnt;
        }
        cout<<ans<<endl;
    }
    return 0;
}