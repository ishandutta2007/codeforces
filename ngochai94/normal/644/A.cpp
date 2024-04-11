#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,a,b,ans[111][111];
vector<int> odd,even;

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>a>>b;
    int c=((a+1)/2)*((b+1)/2)+(a/2)*(b/2);
    int d=((a+1)/2)*(b/2)+(a/2)*((b+1)/2);
    if((n+1)/2>c||n/2>d) cout<<-1;
    else{
        For(i,1,n+1) if(i&1) odd.pb(i);
        else even.pb(i);
        For(i,0,a) For(j,0,b) {
            if((i+j)&1) {
                if(even.empty()) ans[i][j]=0;
                else {
                    ans[i][j]=even.back();
                    even.pop_back();
                }
            }
            else{
                if(odd.empty()) ans[i][j]=0;
                else{
                    ans[i][j]=odd.back();
                    odd.pop_back();
                }
            }
        }
        For(i,0,a){
            For(j,0,b) cout<<ans[i][j]<<' ';
            cout<<endl;
        }
    }
}