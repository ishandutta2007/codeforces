#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;cin>>t;
    ll x=0ll;
    vector<ll>v={1ll};
    int pos=0;
    for (int i=1;i<=t;i++){
        string s;cin>>s;
        if (s=="for"){
            ll a;cin>>a;
            v.push_back(min(v.back()*a*1ll,(1ll<<32)));
            pos++;
        }
        if (s=="end"){
            v.pop_back();
        }
        if (s=="add"){
            x+=v.back()*1ll;
            x=min(x,(1ll<<32));
        }

    }
    if (x>=(1ll<<32)){
                cout<<"OVERFLOW!!!";
                return 0;
    }
    cout<<x;
	return 0;
}