#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int s,len,t,id;
	bool operator<(const node c)const{return s<c.s;}
}a[25];

const int inf=0x3f3f3f3f;
int n,p;
pii d[4200000];
int fr[4200000],lab[25],tp[25];

void getans(int x,int id){
	if(!x) return;
	lab[a[fr[x]].id]=id,tp[a[fr[x]].id]=d[x].fi-a[fr[x]].t;
	getans(x^(1<<(fr[x]-1)),id);
}

int main(){
	n=readint(); p=readint();
	for(int i=1;i<=n;i++) a[i].s=readint(),a[i].len=readint(),a[i].t=readint(),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<(1<<n);i++) d[i]=mp(inf,0);
	d[0]=mp(1,0);
	for(int i=0;i<(1<<n)-1;i++){
		if(d[i].fi==inf) continue;
		int tpl=d[i].fi,tnum=d[i].se;
		if(tpl<=a[tnum].s+a[tnum].len-1) tpl=a[tnum].s+a[tnum].len;
		while(tnum<n&&tpl>=a[tnum+1].s) tpl=a[tnum+1].s+a[tnum+1].len,tnum++;
		for(int j=tnum+1;j<=n;j++){
			if((i>>(j-1))&1) continue;
			int pl=tpl,num=tnum;
			while(num<n){
				int to=pl+a[j].t,fl=0;
				for(int k=num+1;k<=n;k++){
					if(to<a[k].s){
						if(chkmin(d[i|(1<<(j-1))],mp(to,k-1))) fr[i|(1<<(j-1))]=j;
//						cout<<"chk "<<i<<' '<<j<<' '<<d[i].fi<<' '<<d[i].se<<' '<<to<<' '<<k-1<<endl;
						fl=1;
						break;
					}
					num=k,pl=a[k].s+a[k].len;
					if(j==k) break;
					if((i>>(k-1))&1) break;
				}
				if(fl) break;
				while(num<n&&pl>=a[num+1].s) pl=a[num+1].s+a[num+1].len,num++;
				if(num>=j) break;
			}
		}
	}
	if(p==2){
		for(int i=0;i<(1<<n);i++){
			if(d[i].fi<inf&&d[(1<<n)-i-1].fi<inf){
				printf("YES\n");
				getans(i,1);
				getans((1<<n)-i-1,2);
				for(int j=1;j<=n;j++) printf("%d %d\n",lab[j],tp[j]);
				return 0;
			}
		}
		printf("NO\n");
	}
	else{
		if(d[(1<<n)-1].fi<inf){
			printf("YES\n");
			getans((1<<n)-1,1);
			for(int j=1;j<=n;j++) printf("%d %d\n",lab[j],tp[j]);
		}
		else printf("NO\n");
	}
	return 0;
}