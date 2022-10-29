#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define ui unsigned int
#define vi vector<ui>
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e5+9;
struct node{
	int l,r;
};
struct Stack{
	node s[N];
	int cnt;
	void clear(){cnt=0;}
	void push(node x){s[++cnt]=x;}
	int pop(){return --cnt;}
	int size(){return cnt;}
	node top(){return s[cnt];}
	int find(int x){
		int l=0,r=cnt;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[mid+1].r<x)l=mid+1;
			else r=mid; 
		}
		return l;
	}
}S;
stack<node> s; 
node seg[N];
int sum[N],mini[N];
bool cmp(node a,node b){
	if(a.r^b.r)return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	int t;scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,1,n+1)scanf("%d%d",&seg[i].l,&seg[i].r);
		sort(seg+1,seg+1+n,cmp);
		mini[n+1]=seg[n].r+1;
		sum[n+1]=0;
		while(!s.empty())s.pop();
		per(i,1,n+1){
		//	cout<<i<<"check\n";
			if(s.empty()){
				s.push(seg[i]);
				sum[i]=1;
				mini[i]=seg[i].l;
			}
			else{
				node seg0=s.top();
				if(seg0.l<=seg[i].r){
					mini[i]=seg0.l=min(seg0.l,seg[i].l);
					sum[i]=sum[i+1];
					s.pop();
					s.push(seg0);
				}
				else{
					mini[i]=seg[i].l;
					sum[i]=sum[i+1]+1;
					s.push(seg[i]);
				}
			}
		}
	//	cout<<"OK\n";
		S.clear();
		int ans=0;
		rep(i,1,n+1){
			int tot=S.find(mini[i+1]);
			ans=max(ans,tot+sum[i+1]);
		//	cout<<ans<<"ans\n";
			if(!S.size()){
				S.push(seg[i]);
			}
			else{
				while(S.size()){
					node ss=S.top();
					if(ss.r<seg[i].l){
						S.push(seg[i]);
						break;
					}
					else{
						S.pop();
						if(ss.l<=seg[i].l){
							seg[i].l=ss.l;
							S.push(seg[i]);
							break;
						}
						else if(!S.size()){
							S.push(seg[i]);
							break;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}