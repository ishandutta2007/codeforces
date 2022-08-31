#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,ns,nt;
char s[400005],t[400005],ts[400005],tt[400005];
pii ps[400005],pt[400005];
vector<pii> ans;

void perform(int x,int y){
	for(int i=y+1;i<=n-x+y;i++) ts[i]=s[i+x-y];
	for(int i=x+1;i<=m-y+x;i++) tt[i]=t[i+y-x];
	for(int i=1;i<=x;i++) tt[i]=s[i];
	for(int i=1;i<=y;i++) ts[i]=t[i];
	swap(s,ts),swap(t,tt);
	int tn=n-x+y,tm=m+x-y;
	n=tn,m=tm;
//	cout<<"perform "<<x<<' '<<y<<endl;
//	for(int i=1;i<=n;i++) cout<<s[i];
//	cout<<endl;
//	for(int i=1;i<=m;i++) cout<<t[i];
//	cout<<endl;
}

void init(){
	ns=nt=0;
	for(int i=2;i<=n;i++) if(s[i]!=s[i-1]) ps[++ns]=mp(i-1,s[i-1]-'a');
	ps[++ns]=mp(n,s[n]-'a');
	for(int i=2;i<=m;i++) if(t[i]!=t[i-1]) pt[++nt]=mp(i-1,t[i-1]-'a');
	pt[++nt]=mp(m,t[m]-'a');
}

int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	int as=s[1]-'a',at=t[1]-'a';
	init();
	if(ns==1&&as==at&&nt%2==0&&(nt/2&1)){
		int l=nt/2;
		ans.pb(mp(0,pt[l].fi));
		perform(0,pt[l].fi);
		init();
	}
	else if(nt==1&&as==at&&ns%2==0&&(ns/2&1)){
		int l=ns/2;
		ans.pb(mp(ps[l].fi,0));
		perform(ps[l].fi,0);
		init();
	}
	if(abs(ns-nt)>2){
		if(ns<nt){
			int tmp=(nt-ns+1)/2;
			if((tmp^(as==at))&1) tmp--;
			ans.pb(mp(ps[1].fi,pt[tmp+1].fi));
			perform(ps[1].fi,pt[tmp+1].fi);
			init();
		}
		else{
			int tmp=(ns-nt+1)/2;
			if((tmp^(as==at))&1) tmp--;
			ans.pb(mp(ps[tmp+1].fi,pt[1].fi));
			perform(ps[tmp+1].fi,pt[1].fi);
			init();
		}
	}
//	cout<<"ps ";
//	for(int i=1;i<=ns;i++) cout<<ps[i].fi<<' ';
//	cout<<endl;
//	cout<<"pt ";
//	for(int i=1;i<=nt;i++) cout<<pt[i].fi<<' ';
//	cout<<endl;
	if(ns>=nt&&s[1]==t[1]){
		ans.pb(mp(ps[1].fi,0));
		perform(ps[1].fi,0);
		init();
	}
	else if(ns<nt&&s[1]==t[1]){
		ans.pb(mp(0,pt[1].fi));
		perform(0,pt[1].fi);
		init();
	}
	int vals=0,valt=0;
	for(int i=1;i<min(ns,nt)+(abs(ns-nt)==2);i++){
		ans.pb(mp(ps[i].fi+vals,pt[i].fi+valt));
//		perform(ps[i].fi+vals,pt[i].fi+valt);
		int tmp=pt[i].fi+valt-ps[i].fi-vals;
		vals+=tmp,valt-=tmp;
	}
	if(ns<nt) ans.pb(mp(ps[ns].fi+vals,pt[nt-1].fi+valt));
	else if(ns>nt) ans.pb(mp(ps[ns-1].fi+vals,pt[nt].fi+valt));
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}