#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n;
ll v[100001],t[100001];
ll ans,sum;
multiset<ll> st;

int main(){
    scanf("%d",&n);
    F(i,1,n) scanf("%lld",v+i);
    F(i,1,n) scanf("%lld",t+i);
    F(i,1,n){
        st.insert(v[i]+sum);
        multiset<ll>::iterator it,it2,it3;
        sum+=t[i];
        ans=t[i]*st.size();
        it=st.lower_bound(sum+1);
        for(it2=st.begin();it2!=st.end()&&it2!=it;){
            ans+=*it2-sum;
            it3=it2; ++it2;
            st.erase(it3);
        }
        printf("%lld\n",ans);
    }
    return 0;
}