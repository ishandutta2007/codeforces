#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e3+5;
int n,m,q,u[maxn*maxn],v[maxn*maxn],w[maxn*maxn];
int fa[maxn];
bool t[maxn];
void findset(int x){
	if(fa[x]==x) return;
	findset(fa[x]);
	t[x]^=t[fa[x]];
	fa[x]=fa[fa[x]];
}
vector<int> merge(vector<int> a,vector<int> b){
	int cur=0;
	vector<int> ans,tmp;
	auto ins=[&ans,&tmp](int x){
		tmp.push_back(u[x]);
		tmp.push_back(v[x]);
		findset(u[x]);
		findset(v[x]);
		if(fa[u[x]]==fa[v[x]]){
			if(!(t[u[x]]^t[v[x]])){
				ans.push_back(x);
				for(int j:tmp){
					fa[j]=j;
					t[j]=0;
				}
				return 1;
			}
			return 0;
		}
		t[fa[v[x]]]=!t[v[x]];
		fa[fa[v[x]]]=u[x];
		ans.push_back(x);
		return 0;
	};
	for(int i:a){
		while(cur<(int)b.size()&&w[b[cur]]>w[i]){
			if(ins(b[cur])) return ans;
			cur++;
		}
		if(ins(i)) return ans;
	}
	for(int i=cur;i<(int)b.size();i++)
		if(ins(b[i])) return ans;
	for(int j:tmp){
		fa[j]=j;
		t[j]=0;
	}
	return ans;
}
struct node{
	int l,r;
	node* ch[2];
	vector<int> res;
	node(int l,int r):l(l),r(r){
		if(l==r){
			res.push_back(r);
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		res=merge(ch[0]->res,ch[1]->res);
	}
	vector<int> query(int ql,int qr){
		if(ql<=l&&qr>=r) return res;
		if(qr<=ch[0]->r) return ch[0]->query(ql,qr);
		else if(ql>=ch[1]->l) return ch[1]->query(ql,qr);
		else return merge(ch[0]->query(ql,qr),ch[1]->query(ql,qr));
	}
}*rt;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	for(int i=1;i<=m;i++){
		u[i]=readint();
		v[i]=readint();
		w[i]=readint();
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	rt=new node(1,m);
	while(q--){
		int l,r;
		l=readint();
		r=readint();
		vector<int> res=rt->query(l,r),tmp;
		int ans=-1;
		for(int i:res){
			tmp.push_back(u[i]);
			tmp.push_back(v[i]);
			findset(u[i]);
			findset(v[i]);
			if(fa[u[i]]==fa[v[i]]){
				if(!(t[u[i]]^t[v[i]])){
					ans=w[i];
					for(int j:tmp){
						fa[j]=j;
						t[j]=0;
					}
				}
				continue;
			}
			t[fa[v[i]]]=!t[v[i]];
			fa[fa[v[i]]]=u[i];
		}
		for(int i:tmp){
			fa[i]=i;
			t[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}