#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll bpw(ll a, ll k){
    if(!k)return 1;
    ll tmp = bpw(a,k>>1);
    tmp*=tmp;
    tmp%=mod;
    if(k&1)tmp=(tmp*a)%mod;
    return tmp;
}

void solve() {
    int n,m;
    cin>>n>>m;
    int z=0,o=0;
    for (int i = 0;i <n;i++) {
        string s;
        cin>>s;
        for (char c:  s){
            if(c=='#')o++;
            else z++;
        }
    }
    if(z==0){
        cout<<(bpw(2,o)-1+mod)%mod<<'\n';
    }
    else{
        cout<<(bpw(2,o))<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}