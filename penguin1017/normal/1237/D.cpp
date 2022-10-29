#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define lowbit(x) ((x)&(-x)) 
using namespace std;
const int N=(int)1e5+9;
struct node{
	int val,num;
	bool operator <(const node&a) const{
		if(val^a.val)return val<a.val;
		return num<a.num;
	} 
};
int a[N],pos[N];
int main(){
	int n; 
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",&a[i]);
	priority_queue<node> PQ;
	int flag=0,mini=a[0],maxn=a[0];
	rep(i,0,n)mini=min(a[i],mini),maxn=max(a[i],maxn);
	if(mini*2>=maxn){
		rep(i,0,n)printf("-1 ");
		return 0;
	}
	for(int i=0;;i++){
		if(PQ.empty()){
			PQ.push((node){a[i%n],i});
			continue;
		}
		node w=PQ.top();
		while(a[i%n]*2<w.val){
			if(w.num>=n){
				flag=i;
				break;
			}
			pos[w.num]=i;
			PQ.pop();
			if(PQ.empty())break;
			else w=PQ.top(); 
		}
		if(flag)break;
		PQ.push((node){a[i%n],i});
	}
	pos[n]=flag;
	per(i,0,n){
		if(!pos[i])pos[i]=pos[i+1];
		else pos[i]=min(pos[i],pos[i+1]);
	}
	rep(i,0,n)printf("%d ",pos[i]-i);
}