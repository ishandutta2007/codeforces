#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
 
const int mod=998244353;
typedef long long ll;
 
ll quickmod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
 
ll inv(ll x){
    return quickmod(x,mod-2);
}
 
int main()
{
	int n,q;
	cin>>n>>q;
	vector<ll> p(n+1);
	for(int i=1;i<=n;i++){
        cin>>p[i];
        p[i]=p[i]*inv(100)%mod;
	}
	vector<ll> a(n+1);
	vector<ll> sufmul(n+2);
	vector<ll> sufsuma(n+2);
	sufmul[n+1]=1;
	sufsuma[n+1]=0;
	for(int i=n;i>=1;i--){
        ll pre=i==n?1:a[i+1];
        a[i]=pre*inv(p[i])%mod;
        sufsuma[i]=(sufsuma[i+1]+a[i])%mod;
        sufmul[i]=sufmul[i+1]*p[i]%mod;
	}
	auto cal=[&](int l,int r)->ll{
	    r--;
        ll res=(sufsuma[l]-sufsuma[r+1]+mod)%mod;
        res=sufmul[r+1]*res%mod;
        return res;
	};
	set<int> st;
	st.insert(1);
	st.insert(n+1);
	ll res=cal(1,n+1);
	while(q--){
        int x;
        cin>>x;
        if(st.count(x)==0){
            st.insert(x);
            auto it=st.find(x);
            auto itr=it;
            ++itr;
            auto itl=it;
            --itl;
            res-=cal(*itl,*itr);
            res+=cal(*itl,*it);
            res+=cal(*it,*itr);
        }else {
            auto it=st.find(x);
            auto itr=it;
            ++itr;
            auto itl=it;
            --itl;
            res-=cal(*itl,*it);
            res-=cal(*it,*itr);
            res+=cal(*itl,*itr);
            st.erase(x);
        }
        res%=mod;
        if(res<0)res+=mod;
        cout<<res<<endl;
	}
}