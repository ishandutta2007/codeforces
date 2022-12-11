#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
vector<int> a[maxn];
int sum[maxn];
map<int, int> mp;
int main()
{
    int k; cin>>k;
    for(int i = 0; i < k; ++i){
        int n; scanf("%d", &n);
        sum[i] = 0;
        while(n--){
            int x; scanf("%d", &x); a[i].pb(x); sum[i] += x;
        }
    }
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < a[i].size(); ++j){
            int t = sum[i] - a[i][j];
            if(mp.find(t) != mp.end()){
                cout<<"YES"<<endl;
                int id = mp[t]; cout<<id+1;
                for(int l = 0; l < a[id].size(); ++l){
                    if(sum[id]-a[id][l] == t){
                        cout<<" "<<l+1<<endl; break;
                    }
                }
                cout<<i+1<<" "<<j+1<<endl;return 0;
            }
        }
        for(int j = 0; j < a[i].size(); ++j){
            mp[sum[i]-a[i][j]] = i;
        }
    }
    cout<<"NO"<<endl;
}