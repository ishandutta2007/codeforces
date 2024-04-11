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
	int lazy,sum;
}t[600000];

int n;
int cnt[26];
char s[200005];
set<pii> s1;
set<pii> s2[26];
vector<pii> ans;

void build(int id,int l,int r){
	t[id].sum=t[id].lazy=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id,int l,int r){
	if(t[id].lazy){
		int mid=(l+r)/2;
		t[id<<1].sum=mid-l+1,t[id<<1].lazy=t[id].lazy;
		t[id<<1|1].sum=r-mid,t[id<<1|1].lazy=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return (void)(t[id].sum=r-l+1,t[id].lazy=1);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr);
	else change(id<<1,l,mid,ql,mid),change(id<<1|1,mid+1,r,mid+1,qr);
	t[id].sum=t[id<<1].sum+t[id<<1|1].sum;
}

int query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id].sum;
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	int T=readint();
	while(T--){
		scanf("%s",s+1); n=strlen(s+1);
		build(1,1,n);
		for(int i=0;i<26;i++) s2[i].clear(),cnt[i]=0;
		s1.clear();
		for(int i=1;i<n;i++) if(s[i]==s[i+1]) s1.insert(mp(i,s[i]-'a')),cnt[s[i]-'a']++;
		for(auto it1=s1.begin();it1!=s1.end();it1++){
			auto it2=it1; it2++;
			if(it2==s1.end()) break;
			if(it1->se==it2->se) continue;
			s2[it1->se].insert(mp(it1->fi,it2->fi));
			s2[it2->se].insert(mp(it1->fi,it2->fi));
		}
		ans.clear();
		while(1){
//			cout<<"s1 "<<endl;
//			for(auto x:s1) cout<<x.fi<<' '<<x.se<<endl;
//			cout<<"s2 "<<endl;
//			for(int i=0;i<26;i++){
//				for(auto x:s2[i]) cout<<x.fi<<' '<<x.se<<endl;
//			}
			int maxa=0,opt=-1;
			for(int i=0;i<26;i++) if(chkmax(maxa,cnt[i])) opt=i;
			if(opt<0) break;
			if(s2[opt].size()==0){
				for(auto x:s1){
					int tmp=x.fi-query(1,1,n,1,x.fi);
					ans.pb(mp(tmp,tmp));
					change(1,1,n,x.fi,x.fi);
				}
				break;
			}
			pii x=*s2[opt].begin();
			s2[opt].erase(x);
			if(s[x.fi]-'a'==opt) s2[s[x.se]-'a'].erase(x);
			else s2[s[x.fi]-'a'].erase(x);
			ans.pb(mp(x.fi+1-query(1,1,n,1,x.fi),x.se-query(1,1,n,1,x.se-1)));
//			cout<<"test "<<x.fi+1<<' '<<x.se<<endl;
			change(1,1,n,x.fi+1,x.se);
			auto it1=s1.lower_bound(mp(x.fi,-1)),it2=s1.lower_bound(mp(x.se,-1));
			cnt[s[x.fi]-'a']--,cnt[s[x.se]-'a']--;
			if(it1!=s1.begin()){
				auto it3=it1,it4=it2; it3--,it4++;
				if(it3->se!=it1->se){
					s2[it3->se].erase(mp(it3->fi,it1->fi));
					s2[it1->se].erase(mp(it3->fi,it1->fi));
				}
				if(it4!=s1.end()){
					if(it2->se!=it4->se){
						s2[it4->se].erase(mp(it2->fi,it4->fi));
						s2[it2->se].erase(mp(it2->fi,it4->fi));
					}
					if(it3->se!=it4->se){
						s2[it3->se].insert(mp(it3->fi,it4->fi));
						s2[it4->se].insert(mp(it3->fi,it4->fi));
					}
				}
			}
			else{
				auto it4=it2; it4++;
				if(it4!=s1.end()&&it2->se!=it4->se){
					s2[it4->se].erase(mp(it2->fi,it4->fi));
					s2[it2->se].erase(mp(it2->fi,it4->fi));
				}
			}
			s1.erase(it1),s1.erase(it2);
		}
		ans.pb(mp(1,n-query(1,1,n,1,n)));
		printf("%d\n",ans.size());
		for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	}
	return 0;
}