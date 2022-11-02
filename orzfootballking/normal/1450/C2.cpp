/*


DP





ll int
 dp 









*/
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
char c[305][305];
void solve(){
    int cnt1[3]={},cnt2[3]={};
    int n;
    cin>>n;
    int num=n*n;
    FOR(i,1,n){
        FOR(j,1,n){
            cin>>c[i][j];
            if(c[i][j]=='X'){
                cnt1[(i+j)%3]++;
            }else if(c[i][j]=='O'){
                cnt2[(i+j)%3]++;
            }else num--;
        }
    }
    rep(t1,0,3){
        rep(t2,0,3){
            if(t1==t2)continue;
            if(cnt1[t1]+cnt2[t2]<=num/3){
                FOR(i,1,n){
                    FOR(j,1,n){
                        if(c[i][j]=='.'){
                            cout<<'.';
                        }else if(c[i][j]=='X'){
                            if((i+j)%3==t1){
                                cout<<'O';
                            }else cout<<'X';
                        }else if(c[i][j]=='O'){
                            if((i+j)%3==t2){
                                cout<<'X';
                            }else cout<<'O';
                        }
                    }
                    cout<<'\n';
                }
                RE ;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    RE 0;
}