#include<bits/stdc++.h>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int root[200005],cntnode;
int mini[8000005],n;
int ch[8000005][2],maxi=2e5,tag[8000005];
void pushdown(int x){
	if(ch[x][0]){
		tag[ch[x][0]]+=tag[x];
		mini[ch[x][0]]+=tag[x];
	}
	if(ch[x][1]){
		tag[ch[x][1]]+=tag[x];
		mini[ch[x][1]]+=tag[x];
	}
	tag[x]=0;
}
void update(int &x,int tx,int l,int r,int it,int val){
	x=++cntnode;
	ch[x][0]=ch[tx][0];ch[x][1]=ch[tx][1];
	mini[x]=mini[tx];
	if(l==r){
		mini[x]=val;RE;
	}
	int mid=(l+r)>>1;
	pushdown(tx);
	if(mid>=it)update(ch[x][0],ch[tx][0],l,mid,it,val);
	else update(ch[x][1],ch[tx][1],mid+1,r,it,val);
	mini[x]=min(mini[ch[x][0]],mini[ch[x][1]]);
}
int get(int x,int l,int r,int it){
	if(!x)RE 1e18;
	if(l==r)RE mini[x];
	int mid=(l+r)>>1;
	pushdown(x);
	if(mid>=it)RE get(ch[x][0],l,mid,it);
	else RE get(ch[x][1],mid+1,r,it);
}
void merge(int &x,int x1,int x2,int l,int r){
	if(!x1||!x2){
		x=x1+x2;RE;
	}
	if(l==r){
		if(mini[x1]>mini[x2])x=x2;else x=x1;
		RE;
	}
	x=++cntnode;
	int mid=(l+r)>>1;
	pushdown(x1);pushdown(x2);
	merge(ch[x][0],ch[x1][0],ch[x2][0],l,mid);
	merge(ch[x][1],ch[x1][1],ch[x2][1],mid+1,r);
	mini[x]=min(mini[ch[x][0]],mini[ch[x][1]]);
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int d;
	mini[0]=1e18;
	cin>>n>>d;
	stack<int> st;
	update(root[0],0,0,maxi,0,0);
	FOR(i,1,n){
		string s;
		cin>>s;
		if(s=="set"){
			int x,y;
			cin>>x>>y;
			if(x==d){
				update(root[i],root[i-1],0,maxi,x,1e18);
				tag[root[i]]+=y;mini[root[i]]+=y;
				continue;
			}
			int t=mini[root[i-1]];
			update(root[i],root[i-1],0,maxi,x,t-y);
			tag[root[i]]+=y;mini[root[i]]+=y;
		}else if(s=="if"){
			int x;
			cin>>x;
			int now=get(root[i-1],0,maxi,x);
			update(root[i-1],root[i-1],0,maxi,x,1e18);
			update(root[i],0,0,maxi,x,now);
			st.emplace(i);
		}else{
			int pos=st.top();st.pop();
			merge(root[i],root[i-1],root[pos-1],0,maxi);
		}
//		cout<<mini[root[i]]<<'\n';
	}
	cout<<mini[root[n]];
	RE 0;
}