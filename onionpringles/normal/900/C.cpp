#include <bits/stdc++.h>
using namespace std;
int a[101010];
int chk[101010];
int chk2[101010];
const int B=1<<17;
int tr[B<<1];
int get(int l,int r){
	int ans=0;
	for(l+=B,r+=B;l/2!=r/2;l/=2,r/=2){
		if(!(l&1))ans+=tr[l+1];
		if(r&1)ans+=tr[r-1];
	}
	return ans;
}
void upd(int i){
	for(i+=B;i;i/=2)tr[i]++;
}
typedef pair<int,int> pii;
int main(){
	set<int> S;
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		auto it=S.lower_bound(a[i]);
		if(it != S.end()){
			it++;
			if(it==S.end())chk[i]=1;
		}
		else chk2[i]=1;
		S.insert(a[i]);
	}
	pii ans = {-22,0};
	for(int i=n-1;i>=0;i--){
		ans=max(ans,pii(get(-1,a[i])-chk2[i],-a[i]));
		if(chk[i])upd(a[i]);
	}
	printf("%d\n",-ans.second);
}