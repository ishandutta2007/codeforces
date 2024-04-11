#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,a[100010][2],b[100010][2],bj[800080],tr[800080];
pair<int,int> ques[200020];
map<int,int> ma;
void pushdown(int wh){
	if (bj[wh]){
		bj[wh<<1]=tr[wh<<1]=bj[wh<<1|1]=tr[wh<<1|1]=1;
		bj[wh]=0;
	}
}
int get(int wh,int l,int r,int x,int y){
	if (y<l||r<x) return 0;
	if (x<=l&&r<=y) return tr[wh];
	pushdown(wh);
	int mid=(l+r)/2;
	return get(wh<<1,l,mid,x,y)|get(wh<<1|1,mid+1,r,x,y);
}
void ins(int wh,int l,int r,int x,int y){
	if (y<l||r<x) return;
	if (x<=l&&r<=y){
		tr[wh]=1;
		bj[wh]=1;
		return;
	}
	pushdown(wh);
	int mid=(l+r)/2;
	ins(wh<<1,l,mid,x,y);
	ins(wh<<1|1,mid+1,r,x,y);
	tr[wh]=tr[wh<<1]|tr[wh<<1|1];
}
int f;
int main(){
	//freopen("D.in","r",stdin);
	//freopen("DD.out","w",stdout);
	f=1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&b[i][0],&b[i][1]);
	for (int k=0;k<2;k++){
		ma.clear();
		for (int i=0;i<n;i++)
			for (int j=0;j<2;j++) ma[a[i][j]]=1;
		map<int,int>::iterator it;
		int tmp=0;
		for (it=ma.begin();it!=ma.end();it++){
			tmp++;
			it->second=tmp;
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<2;j++) a[i][j]=ma[a[i][j]];
		for (int i=0;i<n;i++) swap(a[i][0],b[i][0]),swap(a[i][1],b[i][1]);
	}
	//for (int i=0;i<n;i++) printf("%d %d %d %d\n",a[i][0],a[i][1],b[i][0],b[i][1]);
	for (int k=0;k<2;k++){
		for (int i=0;i<n;i++){
			ques[2*i]=make_pair(a[i][0],-(i+1));
			ques[2*i+1]=make_pair(a[i][1],(i+1));
		}
		sort(ques,ques+2*n);
		for (int i=0;i<2*n;i++){
			int wh=abs(ques[i].se)-1;
			//printf("%d %d %d\n",ques[i].fi,ques[i].se,wh);
			if (ques[i].se<0){
				if (get(1,1,2*n,b[wh][0],b[wh][1])) f=0;
			}
			else ins(1,1,2*n,b[wh][0],b[wh][1]);
		}
		memset(tr,0,sizeof(tr));
		memset(bj,0,sizeof(bj));
		for (int i=0;i<n;i++) swap(a[i][0],b[i][0]),swap(a[i][1],b[i][1]);
	}
	if (f) printf("YES\n");
	else printf("NO\n");
}