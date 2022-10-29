#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<x<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
const ll Inf=1e18;
char s[N];
int c[26],tot,cc[N],last,top,m,pos,maxn;
pii stk[N];
void sub(int n){
	cc[c[n]]--;
	c[n]--;
	cc[c[n]]++;
}
void upd(){
	while(maxn&&!cc[maxn])--maxn;
}
void add(int i,bool flag){
	if(flag){
	//	cout<<pos<<' '<<i<<' '<<stk[i].fi<<"check\n";
		printf("%d %d\n",pos+1,pos+stk[i].fi);
		sub(stk[top-1].se);
		sub(stk[i].se);
		tot-=2;
		top--;
		upd();
		pos-=stk[top].fi;
		if(i+1<m)stk[i+1].fi+=stk[top].fi;
		else last+=stk[top].fi;
	}
	else{
		stk[top++]=stk[i];
		pos+=stk[i].fi;
	}
}
void solve(){
	scanf("%s",s);
	int n=strlen(s);
	int lt=0;
	m=0;tot=0;
	rep(i,1,n){
		if(s[i]==s[i-1])stk[m++]={i-lt,s[i]-'a'},lt=i,c[s[i]-'a']++,tot++;
	//	cout<<m-1<<' '<<stk[m-1].fi<<' '<<i<<' '<<lt<<"???????\n";
	}
	last=n-lt;
	maxn=0;
	rep(i,0,26)maxn=max(maxn,c[i]),cc[c[i]]++;
	printf("%d\n",max(maxn,(tot+1)>>1)+1);
	top=0;pos=0;
	if(maxn*2<tot){
		//cout<<"case1:\n";
		rep(i,0,m)add(i,top&&stk[top-1].se!=stk[i].se&&maxn*2<tot);
		m=top;
	}
	int id;
	rep(i,0,26)if(maxn==c[i])id=i;
	top=0,pos=0;
	rep(i,0,m){
		//cout<<i<<"case2:\n"; 
		add(i,top&&(stk[top-1].se==id)^(stk[i].se==id));
	}
	rep(i,0,top)printf("%d %d\n",1,stk[i].fi);
	printf("%d %d\n",1,last);
	rep(i,0,n+1)cc[i]=0;
	rep(i,0,26)c[i]=0;
}
int main(){
	int T;
	scanf("%d",&T);
	/*if(T==22982){
		rep(i,1,T+1){
			scanf("%s",s);
			if(i==1604)cout<<s;
		}
		return 0;
	}*/
	while(T--)solve();
}