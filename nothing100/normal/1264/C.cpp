#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,q,p[200020],f[200020],s[200020],qz[200020],ans;
set<int> ch;
int ksm(int x,int y){
	int res=1;
	while (y){
		if (y&1) res=1ll*res*x%mo;
		x=1ll*x*x%mo;
		y=y>>1;
	}
	return res;
}
int main(){
	int ny=ksm(100,mo-2);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	qz[1]=1;
	for (int i=1;i<=n;i++){
		qz[i+1]=1ll*qz[i]*p[i]%mo*ny%mo;
		f[i+1]=(f[i]+1ll*qz[i]*(100-p[i])%mo*ny)%mo;
		s[i+1]=(s[i]+qz[i])%mo;
	}
	ans=1ll*s[n+1]*ksm(mo+1-f[n+1],mo-2)%mo;
	ch.insert(1);
	ch.insert(n+1);
	for (int i=0;i<q;i++){
		int o;
		scanf("%d",&o);
		set<int>::iterator it;
		if (ch.find(o)!=ch.end()){
			ch.erase(o);
			it=ch.upper_bound(o);
			int nxt,pre;
			nxt=*it;
			it--;
			pre=*it;
			int ns,nf;
			ns=(1ll*(s[nxt]-s[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[nxt]-f[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			ans=(ans+1ll*ns*ksm(mo+1-nf,mo-2))%mo;
			ns=(1ll*(s[o]-s[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[o]-f[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			ans=((ans-1ll*ns*ksm(mo+1-nf,mo-2))%mo+mo)%mo;
			ns=(1ll*(s[nxt]-s[o])*ksm(qz[o],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[nxt]-f[o])*ksm(qz[o],mo-2)%mo+mo)%mo;
			ans=((ans-1ll*ns*ksm(mo+1-nf,mo-2))%mo+mo)%mo;
		}
		else{
			it=ch.upper_bound(o);
			int nxt,pre;
			nxt=*it;
			it--;
			pre=*it;
			ch.insert(o);
			int ns,nf;
			ns=(1ll*(s[nxt]-s[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[nxt]-f[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			ans=((ans-1ll*ns*ksm(mo+1-nf,mo-2))%mo+mo)%mo;
			ns=(1ll*(s[o]-s[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[o]-f[pre])*ksm(qz[pre],mo-2)%mo+mo)%mo;
			ans=(ans+1ll*ns*ksm(mo+1-nf,mo-2))%mo;
			ns=(1ll*(s[nxt]-s[o])*ksm(qz[o],mo-2)%mo+mo)%mo;
			nf=(1ll*(f[nxt]-f[o])*ksm(qz[o],mo-2)%mo+mo)%mo;
			ans=(ans+1ll*ns*ksm(mo+1-nf,mo-2))%mo;
		}
		printf("%d\n",ans);
	}
}