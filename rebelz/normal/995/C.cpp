#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll x,y,id,fl;
	double val;
	bool operator<(const node c)const{return val<c.val;}
}a[200005];

const double pi=acos(-1);
int n,m;
int c[100005];
pii k[200005];
multiset<node> s;

void getans(int x,int t){
	if(x<=m) return (void)(c[x]*=t*(a[x].fl?-1:1));
	if(k[x].fi<0) getans(-k[x].fi,-1*t*(a[x].fl?-1:1));
	else getans(k[x].fi,t*(a[x].fl?-1:1));
	if(k[x].se<0) getans(-k[x].se,-1*t*(a[x].fl?-1:1));
	else getans(k[x].se,t*(a[x].fl?-1:1));
}

int main(){
	n=m=readint();
	for(int i=1;i<=n;i++) a[i].x=readint(),a[i].y=readint(),a[i].id=i;
	if(n==1) return printf("1\n"),0;
	for(int i=1;i<=n;i++) c[i]=1;
	for(int i=1;i<=n;i++) if(a[i].y<0||(a[i].y==0&&a[i].x<0)) a[i].x*=-1,a[i].y*=-1,a[i].fl=true;
	for(int i=1;i<=n;i++) a[i].val=atan2(a[i].y,a[i].x);
	for(int i=1;i<=n;i++) s.insert(a[i]);
	while(s.size()>2){
		bool fl=false;
		for(auto it=s.begin(),it1=(++s.begin());it1!=s.end();it++,it1++){
			if(it1->val-it->val<=pi/3){
				k[++n]=mp(it->id,-it1->id);
				a[n].x=it->x-it1->x,a[n].y=it->y-it1->y,a[n].id=n;
				if(a[n].y<0||(a[n].y==0&&a[n].x<0)) a[n].x*=-1,a[n].y*=-1,a[n].fl=true;
				a[n].val=atan2(a[n].y,a[n].x);
				s.insert(a[n]);
				s.erase(it1),s.erase(it);
				fl=true;
				break;
			}
		}
		if(!fl){
			auto it=s.begin(),it1=(--s.end());
			k[++n]=mp(it->id,it1->id);
			a[n].x=it->x+it1->x,a[n].y=it->y+it1->y,a[n].id=n;
			if(a[n].y<0||(a[n].y==0&&a[n].x<0)) a[n].x*=-1,a[n].y*=-1,a[n].fl=true;
			a[n].val=atan2(a[n].y,a[n].x);
			s.insert(a[n]);
			s.erase(it1),s.erase(it);
			break;
		}
	}
	auto it=s.begin(),it1=++s.begin();
	if(it->x*it1->x+it->y*it1->y>0){
		k[++n]=mp(it->id,-it1->id);
		a[n].x=it->x-it1->x,a[n].y=it->y-it1->y,a[n].id=n;
		if(a[n].y<0||(a[n].y==0&&a[n].x<0)) a[n].x*=-1,a[n].y*=-1,a[n].fl=true;
		a[n].val=atan2(a[n].y,a[n].x);
		s.insert(a[n]);
		s.erase(it1),s.erase(it);
	}
	else{
		k[++n]=mp(it->id,it1->id);
		a[n].x=it->x+it1->x,a[n].y=it->y+it1->y,a[n].id=n;
		if(a[n].y<0||(a[n].y==0&&a[n].x<0)) a[n].x*=-1,a[n].y*=-1,a[n].fl=true;
		a[n].val=atan2(a[n].y,a[n].x);
		s.insert(a[n]);
		s.erase(it1),s.erase(it);
	}
//	for(int i=1;i<=n;i++) cout<<a[i].fl<<' '<<k[i].fi<<' '<<k[i].se<<' '<<a[i].x<<' '<<a[i].y<<endl;
	getans(n,1);
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	printf("\n");
	return 0;
}