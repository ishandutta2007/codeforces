#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 1e6 + 50;
int vis[maxn], t[maxn];
int a[maxn];
vector<int> ans;
int n;
stack<int> s;
int main()
{
    cin>>n;
    int ned = 0;
    int ok = 1;
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i){
        int x;
        x = a[i];
        if(x < 0){//
            x = -x;
            if(t[x] == 0){//
                ok = 0; break;
            }
            else{//
                t[x]--;
                ned--;//1
            }
            if(ned == 0){
                int pre = 0;
                if(ans.size()) pre = ans[ans.size()-1];
                for(int j = pre+1; j <= i; ++j){
                    x = a[j]; if(x < 0) continue; vis[x] = 0;
                }
                ans.push_back(i);
            }
        }
        else{//
            if(vis[x]){
                ok = 0; break;
            }
            else {
                ned ++;
                vis[x] = 1;
                t[x]++;
            }
        }
    }
    if(ned == 0 && ok){
        cout<<ans.size()<<endl;
        for(int i = ans.size()-1; i > 0; --i){
            ans[i] = ans[i] - ans[i-1];
        }
        for(int i = 0; i < ans.size(); ++i){
            if(i > 0) printf(" ");
            printf("%d", ans[i]);
        }printf("\n");
    }
    else printf("-1\n");
}