// xtqqwq
#include<bits/stdc++.h>

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

const int base=19260817;
int n,k,q,m,blo;
int top1[1005],top2[1005],s1[1005][1005],s2[1005][1005],lf[1005],rg[1005],bl[100005],a[100005];
ull h1[1005][1005],h2[1005][1005],pw[1005];
bool fl[1005];

void rebuild(int b){
	top1[b]=top2[b]=fl[b]=0;
	for(int i=lf[b];i<=rg[b];i++){
		if(a[i]>0) s1[b][++top1[b]]=a[i];
		else{
			if(top1[b]){
				if(s1[b][top1[b]]!=-a[i]) fl[b]=1;
				else top1[b]--;
			}
			else s2[b][++top2[b]]=-a[i];
		}
	}
	reverse(s2[b]+1,s2[b]+top2[b]+1);
	for(int i=1;i<=top1[b];i++) h1[b][i]=h1[b][i-1]*base+s1[b][i];
	for(int i=1;i<=top2[b];i++) h2[b][i]=h2[b][i-1]*base+s2[b][i];
//	cout<<"rebuild "<<b<<endl;
//	for(int i=1;i<=top1[b];i++) cout<<s1[b][i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=top2[b];i++) cout<<s2[b][i]<<' ';
//	cout<<endl;
}

void init(){
	blo=sqrt(n);
	for(int i=1;i<=n;i+=blo) lf[++m]=i,rg[m]=min(i+blo-1,n);
	for(int i=1;i<=m;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
	for(int i=1;i<=m;i++) rebuild(i);
	pw[0]=1;
	for(int i=1;i<=blo;i++) pw[i]=pw[i-1]*base;
}

ull gethsh1(int b,int l,int r){return h1[b][r]-h1[b][l-1]*pw[r-l+1];}
ull gethsh2(int b,int l,int r){return h2[b][r]-h2[b][l-1]*pw[r-l+1];}

bool getans(int l,int r){
	int lb=bl[l],rb=bl[r];
	stack<int> stk;
	if(lb==rb){
		for(int i=l;i<=r;i++){
			if(a[i]>0) stk.push(a[i]);
			else if(stk.empty()) return false;
			else if(stk.top()!=-a[i]) return false;
			else stk.pop();
		}
		if(!stk.empty()) return false;
		return true;
	}
	for(int i=l;i<=rg[lb];i++){
		if(a[i]>0) stk.push(a[i]);
		else if(stk.empty()) return false;
		else if(stk.top()!=-a[i]) return false;
		else stk.pop();
	}
	vector<pii> vec;
	for(int i=lb+1;i<=rb-1;i++){
		if(fl[i]) return false;
		int pl=top2[i];
		while(pl){
			if(vec.empty()){
				for(int j=pl;j>=1;j--){
					if(stk.empty()) return false;
					else if(stk.top()!=s2[i][j]) return false;
					else stk.pop();
				}
				break;
			}
			pii tmp=vec.back();
			int len=min(tmp.se,pl);
			if(gethsh2(i,pl-len+1,pl)!=gethsh1(tmp.fi,tmp.se-len+1,tmp.se)) return false;
			pl-=len;
			tmp.se-=len;
			if(!tmp.se) vec.pop_back();
			else vec[vec.size()-1]=tmp;
		}
		if(top1[i]) vec.pb(mp(i,top1[i]));
	}
	stack<int> stk2;
	for(int i=lf[rb];i<=r;i++){
		if(a[i]>0) stk2.push(a[i]);
		else{
			if(!stk2.empty()){
				if(stk2.top()!=-a[i]) return false;
				stk2.pop();
			}
			else if(vec.empty()){
				if(stk.empty()) return false;
				else if(stk.top()!=-a[i]) return false;
				else stk.pop();
			}
			else{
				if(s1[vec.back().fi][vec.back().se]!=-a[i]) return false;
				vec[vec.size()-1].se--;
				if(!vec.back().se) vec.pop_back();
			}
		}
	}
	if(!stk2.empty()||!stk.empty()||!vec.empty()) return false;
	return true;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	init();
	q=readint();
	int opt,x,y;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			a[x]=y;
			rebuild(bl[x]);
		}
		else{
			if(getans(x,y)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}