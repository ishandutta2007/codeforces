#include <set>
#include <cstdio>
using namespace std;
const int Maxm=400000;
int n,m,q,rt,tot;
int ml[Maxm<<2|5],mr[Maxm<<2|5],ans[Maxm<<2|5];
set<int> s[Maxm+5];
struct tree{
	int x,v,ls,rs;
}t[Maxm<<2|5];
void upd(int &p,int l,int r,int x,int v,int op){
	if(!p)p=++tot;
	if(l==r){
		if(op==1){
			ml[p]=v;
		}
		else{
			mr[p]=v;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		upd(t[p].ls,l,mid,x,v,op);
	}
	else{
		upd(t[p].rs,mid+1,r,x,v,op);
	}
	ml[p]=min(ml[t[p].ls],ml[t[p].rs]);
	mr[p]=max(mr[t[p].ls],mr[t[p].rs]);
	ans[p]=ans[t[p].ls]|ans[t[p].rs]|(ml[t[p].ls]<=mr[t[p].rs]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<(Maxm<<2);i++){
		ml[i]=1000000000;
		mr[i]=-1000000000;
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if(x&1){
			if(s[x].find(y)==s[x].end()){
				s[x].insert(y);
			}
			else{
				s[x].erase(y);
			}
			int v=1e9;
			if(s[x].size()){
				v=*s[x].begin();
			}
			upd(rt,1,n*2,x,v,1);
		}
		else{
			if(s[x].find(-y)==s[x].end()){
				s[x].insert(-y);
			}
			else{
				s[x].erase(-y);
			}
			int v=-1e9;
			if(s[x].size()){
				v=-*s[x].begin();
			}
			upd(rt,1,n*2,x,v,2);
		}
		if(ans[rt]){
			puts("NO");
		}
		else{
			puts("YES");
		}
	}
	return 0;
}