#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
using namespace std;
 
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