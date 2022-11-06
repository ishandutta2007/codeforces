#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
typedef long long ll;
const int Maxn=(1<<18);
int n,q;
struct Segment{
	int lson,rson;
	ll sum;
	int dep;
	bool lazy_1[20],lazy_2[20];
}seg[Maxn<<2|5];
int id_tot=1;
int a[Maxn+5];
void push_down(int root){
	for(int i=0;i<20;i++){
		if(seg[root].lazy_1[i]){
			seg[seg[root].lson].lazy_1[i]^=1;
			seg[seg[root].rson].lazy_1[i]^=1;
			if(seg[root].dep>=i){
				swap(seg[root].lson,seg[root].rson);
			}
			seg[root].lazy_1[i]=0;
		}
		if(seg[root].lazy_2[i]){
			seg[seg[root].lson].lazy_2[i]^=1;
			seg[seg[root].rson].lazy_2[i]^=1;
			if(seg[root].dep==i){
				swap(seg[root].lson,seg[root].rson);
			}
			seg[root].lazy_2[i]=0;
		}
	}
}
void build(int root=1,int left=1,int right=(1<<n)){
	if(left==right){
		seg[root].sum=a[left];
		return;
	}
	seg[root].lson=++id_tot;
	seg[root].rson=++id_tot;
	seg[seg[root].lson].dep=seg[root].dep+1;
	seg[seg[root].rson].dep=seg[root].dep+1;
	int mid=(left+right)>>1;
	build(seg[root].lson,left,mid);
	build(seg[root].rson,mid+1,right);
	seg[root].sum=seg[seg[root].lson].sum+seg[seg[root].rson].sum;
}
void change(int x,int a,int root=1,int left=1,int right=(1<<n)){
	if(left==right){
		seg[root].sum=a;
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	if(x<=mid){
		change(x,a,seg[root].lson,left,mid);
	}
	else{
		change(x,a,seg[root].rson,mid+1,right);
	}
	seg[root].sum=seg[seg[root].lson].sum+seg[seg[root].rson].sum;
}
ll query(int l,int r,int root=1,int left=1,int right=(1<<n)){
	if(l>right||r<left){
		return 0;
	}
	if(l<=left&&r>=right){
		return seg[root].sum;
	}
	push_down(root);
	int mid=(left+right)>>1;
	return query(l,r,seg[root].lson,left,mid)+query(l,r,seg[root].rson,mid+1,right);
}
void debug(int root=1,int left=1,int right=(1<<n)){
	if(left==right){
		printf("%lld ",seg[root].sum);
		return;
	}
	push_down(root);
	int mid=(left+right)>>1;
	debug(seg[root].lson,left,mid);
	debug(seg[root].rson,mid+1,right);
}
int main(){
	read(n),read(q);
	for(int i=1;i<=(1<<n);i++){
		read(a[i]);
	}
	build();
	for(int i=1;i<=q;i++){
		int op;
		read(op);
		if(op==1){
			int x,k;
			read(x),read(k);
			change(x,k);
		}
		else if(op==2){
			int k;
			read(k);
			k=n-k;
			seg[1].lazy_1[k]^=1;
		}
		else if(op==3){
			int k;
			read(k);
			k=n-k-1;
			seg[1].lazy_2[k]^=1;
		}
		else{
			int l,r;
			read(l),read(r);
			printf("%lld\n",query(l,r));
		}
	}
	return 0;
}