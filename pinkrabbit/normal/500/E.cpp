#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
using namespace std;

int n,q;
int p[200001],h[200001],arr[400001],cnt;
int x[200001],y[200001],o[200001],Ans[200001];
bool cmp(int p1,int p2){return x[p1]>x[p2];}

int dat[1048576],laz[1048576];

void push_down(int i,int l,int r){
	if(!laz[i]) return;
	int mid=l+r>>1;
	laz[i<<1]=laz[i<<1|1]=1;
	dat[i<<1]=arr[mid]-arr[l-1];
	dat[i<<1|1]=arr[r]-arr[mid];
	laz[i]=0;
}

void Ins(int i,int l,int r,int a,int b){
	if(r<a||b<l) return;
	if(a<=l&&r<=b) {dat[i]=arr[r]-arr[l-1]; laz[i]=1; return;}
	push_down(i,l,r);
	int mid=l+r>>1;
	Ins(i<<1,l,mid,a,b); Ins(i<<1|1,mid+1,r,a,b);
	dat[i]=dat[i<<1]+dat[i<<1|1];
}

int Qur(int i,int l,int r,int a,int b){
	if(r<a||b<l) return 0;
	if(a<=l&&r<=b) return dat[i];
	push_down(i,l,r);
	int mid=l+r>>1;
	return Qur(i<<1,l,mid,a,b)+Qur(i<<1|1,mid+1,r,a,b);
}

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",p+i,h+i), arr[cnt++]=p[i], arr[cnt++]=p[i]+h[i];
	sort(arr,arr+cnt); cnt=unique(arr,arr+cnt)-arr;
	F(i,1,n) h[i]=lower_bound(arr,arr+cnt,p[i]+h[i])-arr, p[i]=lower_bound(arr,arr+cnt,p[i])-arr;
	scanf("%d",&q);
	F(i,1,q) scanf("%d%d",x+i,y+i), o[i]=i;
	sort(o+1,o+q+1,cmp);
	int lst=n+1;
	F(i,1,q){
		while(x[o[i]]<lst) --lst, Ins(1,1,cnt,p[lst]+1,h[lst]);
		Ans[o[i]]=arr[p[y[o[i]]]]-arr[p[x[o[i]]]]-Qur(1,1,cnt,p[x[o[i]]]+1,p[y[o[i]]]);
	}
	F(i,1,q) printf("%d\n",Ans[i]);
	return 0;
}