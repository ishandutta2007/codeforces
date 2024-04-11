#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
struct query{
	int pos,val,id;
	bool operator<(const query &q)const{
		return pos<q.pos;
	}
}ques[100010];
struct linear_base{
	int d[21],cnt;
	void insert(int x){
		for(int i=20;~i;i--)
			if(x&(1<<i)){
				if(!d[i]){
					d[i]=x;cnt++;return;
				}
				x^=d[i];
			}
	}
	bool valid(int x){
		for(int i=20;~i;i--)
			if(x&(1<<i)){
				if(!d[i]) return false;
				x^=d[i];
			}
		return true;
	}
}AONYAPAEEMIA;
int n,q,cur=0,x[100010],ans[100010];
int quickpow(int a,int b){
	int ans=1%mod,fac=a%mod;
	while(b){
		if(b&1) ans=1ll*ans*fac%mod;
		fac=1ll*fac*fac%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&ques[i].pos,&ques[i].val);
		ques[i].id=i;
	}
	sort(ques+1,ques+q+1);
	for(int i=1;i<=q;i++){
		while(cur<ques[i].pos) AONYAPAEEMIA.insert(x[++cur]);
		if(AONYAPAEEMIA.valid(ques[i].val)) ans[ques[i].id]=quickpow(2,ques[i].pos-AONYAPAEEMIA.cnt);
		else ans[ques[i].id]=0;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}