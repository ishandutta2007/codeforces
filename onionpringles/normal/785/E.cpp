#include <stdio.h>
#include <set>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
const int B = 1<<18;
os tr[B<<1];
int a[200000];
void rem(int i){
	int x = *tr[B+i].begin();
	for(i+=B;i;i/=2)tr[i].erase(x);
}
void add(int i,int v){
	for(i+=B;i;i/=2)tr[i].insert(v);
}
int cnt(int l,int r,int a,int b){
	int ans=0;
	for(l+=B,r+=B;l/2!=r/2;l/=2,r/=2){
		if(!(l&1))ans+=tr[l+1].order_of_key(b)-tr[l+1].order_of_key(a);
		if(r&1)ans+=tr[r-1].order_of_key(b)-tr[r-1].order_of_key(a);
	}
	return ans;
}
int main(){
	int n,q;scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		tr[B+i].insert(i);a[i]=i;
	}
	for(int i=B-1;i;i--){
		tr[i]=tr[i<<1|1];
		for(auto &x:tr[i<<1])tr[i].insert(x);
	}
	long long cur=0;
	for(int i=0;i<q;i++){
		int l,r;scanf("%d%d",&l,&r);l--;r--;
		if(l>r)swap(l,r);
		if(l==r){
			printf("%lld\n",cur);continue;
		}
		if(a[l]<a[r]){
			cur += 2*cnt(l,r,a[l],a[r])+1;
		}
		else{
			cur -= 2*cnt(l,r,a[r],a[l])+1;
		}
		rem(l);rem(r);
		add(r,a[l]);add(l,a[r]);swap(a[l],a[r]);
		printf("%lld\n",cur);
	}
}