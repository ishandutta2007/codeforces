#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,k;
ll f(int c9,int r){
    int res=0;
    for(int i=0;i<=k;i++)
        if(i+r<10)res+=c9*9+i+r;
        else res+=i+r-9;

    int rem = n-res;

    if(rem%(k+1)||rem<0)return 1e18;

    rem/=k+1;

    ll ans=0;

    if(rem<9)ans=rem;
    else{
        rem-=8;
        ans=rem%9;
        for(int i=1;i<=rem/9;i++)
            ans=ans*10+9;
        ans=ans*10+8;
    }
    for(int i=1;i<=c9;i++)
        ans=ans*10+9;
    ans=ans*10+r;

    return ans;

}

int main() {
    cin >> T;

    while(T--) {
    cin>>n>>k;
    ll ans =1e18;
    for(int c9=0;c9<=16;c9++){
        for(int r=0;r<10;r++){
        ans=min(ans,f(c9,r));
        }
    }
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;

    }
	return 0;
}