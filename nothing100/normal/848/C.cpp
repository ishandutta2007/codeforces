#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct{
	int kind,x,y,z;
}ques[1000010],tmp[1000010];
int n,m,a[100010],tot,q;
LL ans[100010],tr[100010];
set<int> s[100010];
int lowbit(int x){return x&(-x);}
void ins(int x,int y){
	while (x<=n){
		tr[x]+=y;
		x+=lowbit(x);
	}
}
LL get(int x){
	LL tmp=0;
	while (x){
		tmp+=tr[x];
		x-=lowbit(x);
	}
	return tmp;
}
void inse(int x,int y){
	set<int>::iterator itt,it;
	itt=it=s[a[x]].find(x);
	itt++;
	if (it!=s[a[x]].begin()){
		ques[++tot].kind=1;
		it--;
		ques[tot].x=*it;
		it++;
		ques[tot].y=x;
		ques[tot].z=(ques[tot].y-ques[tot].x)*y;
	}
	if (itt!=s[a[x]].end()){
		ques[++tot].kind=1;
		ques[tot].x=x;
		ques[tot].y=*itt;
		ques[tot].z=(ques[tot].y-ques[tot].x)*y;
	}
	if ((it!=s[a[x]].begin())&&(itt!=s[a[x]].end())){
		ques[++tot].kind=1;
		it--;
		ques[tot].x=*it;
		ques[tot].y=*itt;
		ques[tot].z=(ques[tot].y-ques[tot].x)*-y;
	}
}
void cdq(int x,int y){
	if (x==y) return;
	int mid=(x+y)>>1;
	cdq(x,mid);
	cdq(mid+1,y);
	int l=x,r=mid+1,now=x;
	while (l<=mid&&r<=y){
		if (ques[l].x>=ques[r].x){
			if (ques[l].kind==1) ins(ques[l].y,ques[l].z);
			tmp[now++]=ques[l++];
		}
		else{
			if (ques[r].kind==2) ans[ques[r].z]+=get(ques[r].y);
			tmp[now++]=ques[r++];
		}
	}
	while (l<=mid){
		if (ques[l].kind==1) ins(ques[l].y,ques[l].z);
		tmp[now++]=ques[l++];
	}
	while (r<=y){
		if (ques[r].kind==2) ans[ques[r].z]+=get(ques[r].y);
		tmp[now++]=ques[r++];
	}
	for (int i=x;i<=mid;i++)
	if (ques[i].kind==1) ins(ques[i].y,-ques[i].z);
	for (int i=x;i<=y;i++) ques[i]=tmp[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
		inse(i,1);
	}
	for (int i=0;i<m;i++){
		int o,p,t;
		scanf("%d%d%d",&o,&p,&t);
		if (o==1){
			inse(p,-1);
			s[a[p]].erase(p);
			a[p]=t;
			s[a[p]].insert(p);
			inse(p,1);
		}
		else{
			ques[++tot].kind=2;
			ques[tot].x=p;
			ques[tot].y=t;
			ques[tot].z=q++;
		}
	}
	cdq(1,tot);
	for (int i=0;i<q;i++) printf("%lld\n",ans[i]);
}