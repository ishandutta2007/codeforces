#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,q;
namespace Segment_Tree{
	int sum[Maxn<<2|5];
	std::pair<int,int> mn_val[Maxn<<2|5];
	void push_up(int root){
		sum[root]=sum[root<<1]+sum[root<<1|1];
		std::pair<int,int> t=mn_val[root<<1|1];
		t.first+=sum[root<<1];
		mn_val[root]=std::min(mn_val[root<<1],t);
	}
	void update(int x,int v,int root=1,int left=0,int right=2*n+1){
		if(left==right){
			sum[root]=v,mn_val[root]=std::make_pair(v,x);
			return;
		}
		int mid=(left+right)/2;
		if(x<=mid){
			update(x,v,root<<1,left,mid);
		}
		else{
			update(x,v,root<<1|1,mid+1,right);
		}
		push_up(root);
	}
	int query(int l,int r,int root=1,int left=0,int right=2*n+1){
		if(l>right||r<left){
			return 0;
		}
		if(l<=left&&r>=right){
			return sum[root];
		}
		int mid=(left+right)/2;
		return query(l,r,root<<1,left,mid)+query(l,r,root<<1|1,mid+1,right);
	}
}
ll sum_l,sum_r;
int p[Maxn+5],pos[Maxn+5];
int get_val(int u){
	return u<n+1?-1:u==n+1?0:1;
}
int calc(int u,int L,int R){
	int l=u-1,r=u+1;
	if(l<L){
		l+=n+1;
	}
	if(r>R){
		r-=n+1;
	}
	int val_1=pos[u]-pos[l],val_2=pos[r]-pos[u];
	if(val_1<0){
		val_1+=2*n+1;
	}
	if(val_2<0){
		val_2+=2*n+1;
	}
	return val_1+val_2;
}
void update(int x,int v){
	if(x<=n+1){
		sum_l-=calc(x,1,n+1);
	}
	if(x>=n+1){
		sum_r-=calc(x,n+1,2*n+1);
	}
	p[v]=x,pos[x]=v;
	Segment_Tree::update(v,get_val(x));
	if(x<=n+1){
		sum_l+=calc(x,1,n+1);
	}
	if(x>=n+1){
		sum_r+=calc(x,n+1,2*n+1);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=2*n+1;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=2*n+1;i++){
		update(p[i],i);
		Segment_Tree::update(i,get_val(p[i]));
	}
	for(int t=1;t<=q;t++){
		int x,y;
		scanf("%d%d",&x,&y);
		int p_x=p[x],p_y=p[y];
		update(p_x,y),update(p_y,x);
		int k=Segment_Tree::mn_val[1].second;
		int cur_sum=(pos[n+1]<=k?Segment_Tree::query(pos[n+1],k):Segment_Tree::query(k+1,pos[n+1]));
		if(cur_sum!=0){
			printf("%d\n",k);
		}
		else if(sum_l!=2*n+1){
			if(pos[n+1]==2*n+1){
				puts("0");
			}
			else{
				printf("%d\n",pos[n+1]);
			}
		}
		else if(sum_r!=2*n+1){
			printf("%d\n",pos[n+1]-1);
		}
		else{
			puts("-1");
		}
	}
	return 0;
}