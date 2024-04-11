#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int cnt[2];
bool f[2][2][105][105];

void init(int n){
    f[0][0][0][0]=f[0][1][0][0]=1;
    for (int s=1;s<=n;++s){
        for (int x=0;x<=s;++x){
            int y=s-x;
            for (int now:{0,1}){
                f[now][0][x][y]=0;
                f[now][1][x][y]=1;
                if (x){
                    f[now][0][x][y]|=f[now][1][x-1][y];
                    f[now][1][x][y]&=f[now][0][x-1][y];
                }
                if (y){
                    f[now][0][x][y]|=f[now^1][1][x][y-1];
                    f[now][1][x][y]&=f[now][0][x][y-1];
                }
            }
        }
    }
}
void solve(){
    int n; cin>>n;
    cnt[0]=cnt[1]=0;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        ++cnt[(x%2+2)%2];
    }
    cout<<(f[0][0][cnt[0]][cnt[1]]?"Alice":"Bob")<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init(100);
    int T; cin>>T;
    while (T--) solve();
}