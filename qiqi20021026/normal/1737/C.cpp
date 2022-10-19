#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<pair<int,int>> a(3);
        int s,t,sum=0,corner=0;
        auto chk=[&](int x,int y)->int
        {
            return (x==1||x==n)&&(y==1||y==n);
        };
        for (auto &[x,y]:a){
            cin>>x>>y;
            sum+=x+y;
            corner+=x==1||x==n;
            corner+=y==1||y==n;
        }
        cin>>s>>t;
        bool fl=0;
        if (corner==4){
            fl=0;
            for (auto [x,y]:a){
                if (chk(x,y)){
                    fl=x==s||y==t;
                }
            }
        }
        else{
            fl=1;
            for (auto [x,y]:a){
                if ((x+y)%2==sum%2){
                    if ((s+t+x+y)%2==0){
                        if (abs(s-x)%2==1) fl=0;
                    }
                }
            }
        }
        cout<<(fl?"YES":"NO")<<'\n';
    }
}