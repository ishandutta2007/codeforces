#include<bits/stdc++.h>

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct seg{
	int maxa,pl;
}t[1100000];

struct node{
	int k,x,y;
}q[200005];

int n;
int p[400005];
set<int> s[400005];

void build(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void change(int id,int l,int r,int p,int x){
	if(l==r){
		t[id].maxa=x,t[id].pl=p;
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) change(id<<1,l,mid,p,x);
	else change(id<<1|1,mid+1,r,p,x);
	if(t[id<<1].maxa>=t[id<<1|1].maxa) t[id].maxa=t[id<<1].maxa,t[id].pl=t[id<<1].pl;
	else t[id].maxa=t[id<<1|1].maxa,t[id].pl=t[id<<1|1].pl;
}

pii query(int id,int l,int r,int ql,int qr,int x){
	if(l==r) return mp(t[id].maxa,t[id].pl);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,x);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,x);
	pii lson=mp(0,0);
	if(t[id<<1].maxa>x) lson=query(id<<1,l,mid,ql,mid,x);
	if(lson.fi>x) return lson;
	else return query(id<<1|1,mid+1,r,mid+1,qr,x);
}

int main(){
	n=readint();
	char opt[10];
	for(int i=1;i<=n;i++){
		scanf("%s",opt); q[i].x=readint(); q[i].y=readint();
		p[2*i-1]=q[i].x,p[2*i]=q[i].y;
		if(opt[0]=='a') q[i].k=1;
		else if(opt[0]=='r') q[i].k=2;
		else q[i].k=3;
	}
	sort(p+1,p+2*n+1);
	for(int i=1;i<=n;i++) q[i].x=lower_bound(p+1,p+2*n+1,q[i].x)-p,q[i].y=lower_bound(p+1,p+2*n+1,q[i].y)-p;
	for(int i=1;i<=n;i++){
		if(q[i].k==1){
			s[q[i].x].insert(q[i].y);
			auto xx=s[q[i].x].end(); --xx;
			change(1,1,2*n,q[i].x,*xx);
		}
		else if(q[i].k==2){
			s[q[i].x].erase(q[i].y);
			if(s[q[i].x].size()==0) change(1,1,2*n,q[i].x,0);
			else{
				auto xx=s[q[i].x].end(); --xx;
				change(1,1,2*n,q[i].x,*xx);
			}
		}
		else{
			pii tmp=query(1,1,2*n,q[i].x+1,2*n,q[i].y);
			if(tmp.fi<=q[i].y) printf("-1\n");
			else{
				auto num=s[tmp.se].upper_bound(q[i].y);
				printf("%d %d\n",p[tmp.se],p[*num]);
			}
		}
	}
	return 0;
}