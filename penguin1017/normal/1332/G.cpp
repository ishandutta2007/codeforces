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
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
int a[N],stk[N],stk2[N],top,top2,t[N],b[N],c[N],ans[N][3],ans2[N][4];
set<int> s;
bool cmp(int u,int v){
	return a[u]<a[v];
}
bool cmp2(int u,int v){
	return a[u]>a[v];
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	rep(i,1,n+1)scanf("%d",&a[i]);
	s.insert(n+1);
	int r1=0,r2=0;
	per(i,1,n+1){
		while(top){
			int p=stk[top];
		//	cout<<p<<' '<<a[p]<<' '<<a[i]<<"??\n";
			if(a[p]>a[i]){
				--top;
				--t[p];
				if(!t[p])s.insert(p);
				r1=0;
			}
			else{
				break;
			}
		}
		while(top2){
			int p=stk2[top2];
			if(a[p]<a[i]){
				--top2;
				--t[p];
				if(!t[p])s.insert(p);
				r2=0;
			}
			else{
				break;
			}
		}
		b[i]=i+max(r1,r2)+1;
	//	cout<<i<<' '<<b[i]<<' '<<r1<<' '<<r2<<"check\n";
		ans[i][0]=i,ans[i][1]=b[i]-1,ans[i][2]=b[i];
		int s1=lower_bound(stk+1,stk+1+top,i,cmp)-stk-1,s2=lower_bound(stk2+1,stk2+1+top2,i,cmp2)-stk2-1;
		if(s1&&s2){
			c[i]=*s.lower_bound(max(stk[s1],stk2[s2]));
			if(c[i]<=n){
				int u=lower_bound(stk+1,stk+1+top,c[i],greater<int>())-stk,v=lower_bound(stk2+1,stk2+1+top2,c[i],greater<int>())-stk2;
				ans2[i][0]=i;ans2[i][1]=min(stk[u],stk2[v]);ans2[i][2]=max(stk[u],stk2[v]);ans2[i][3]=c[i];
			}
		}
		else c[i]=n+1;
		stk[++top]=i;
		stk2[++top2]=i;
	//	cout<<top<<' '<<stk[top]<<"why\n";
		++r1,++r2;
		t[i]+=2;
		if(i<n&&b[i]>b[i+1]){
			b[i]=b[i+1];
			rep(j,0,3)ans[i][j]=ans[i+1][j]; 
		}
		if(i<n&&c[i]>c[i+1]){
			c[i]=c[i+1];
			rep(j,0,4)ans2[i][j]=ans2[i+1][j];
		}
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(c[l]<=r){
			printf("4\n");
			rep(i,0,4)printf("%d ",ans2[l][i]);
		}
		else if(b[l]<=r){
			printf("3\n");
			rep(i,0,3)printf("%d ",ans[l][i]);
		}
		else printf("0");
		printf("\n");
	}
}
/*
30 27
698632656 525581861 577504542 296603772 998990943 682881766 954895689 281259836 501177498 256330408 76466544 702835982 616513496 248342985 523962020 40996762 511850624 770240476 118371399 223228156 684298386 413908009 791936146 358337607 806286367 436654632 51668240 860274173 306994125 637771786
13 22
16 28
4 8
3 5
10 16
23 27
25 27
19 24
13 28
11 25
2 5
17 26
11 18
7 19
5 8
2 4
15 27
13 24
8 20
28 30
12 15
26 29
18 27
3 11
7 22
10 23
10 29
*/