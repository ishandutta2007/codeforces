#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#define int long long
const int Maxn=600006;
int n;
int w[Maxn],ch[Maxn],fail[Maxn],lstU[Maxn];
int B[Maxn],___; 
void Gf(int i){
	if (i==1) fail[i]=0;
	else{
		int tmp=fail[i-1];
		while (tmp && ch[tmp+1]!=ch[i]){
			tmp=fail[tmp];
		}
		if (ch[tmp+1]==ch[i]){
			fail[i]=tmp+1;
		}
		else{
			fail[i]=0;
		}
		if (ch[i]==ch[fail[i-1]+1]){
			lstU[i-1]=lstU[fail[i-1]];
		}
		else{
			lstU[i-1]=fail[i-1];
		}
		B[i]=B[fail[i]]+1;
	}
	
}
LL tree1[Maxn*4],tree2[Maxn*4],tag[Maxn*4];
int cnt[Maxn*4];
void Push(int p){
	if (tag[p]!=-1){
		
		
		if (cnt[p*2]){
			tag[p*2]=tag[p];
			tree2[p*2]=tag[p]*cnt[p*2];
			tree1[p*2]=tag[p];
		}
		if (cnt[p*2+1]){
			tag[p*2+1]=tag[p];
			tree2[p*2+1]=tag[p]*cnt[p*2+1];
			tree1[p*2+1]=tag[p];
		}
		tag[p]=-1;
		return;
	} 
} 
void Pull(int p){
	cnt[p]=cnt[p*2]+cnt[p*2+1];
	if (!cnt[p]){
		tree1[p]=tree2[p]=0;
		return;
	}
	tree2[p]=tree2[p*2]+tree2[p*2+1];
	tree1[p]=1e18;
	if (cnt[p*2]) tree1[p]=min(tree1[p],tree1[p*2]);
	if (cnt[p*2+1]) tree1[p]=min(tree1[p],tree1[p*2+1]);
	//tree1[p]=min(tree1[p*2],tree1[p*2+1]);
}
void Del(int p,int l,int r,int pos){
	if (l==r){
		assert(cnt[p]);
		tree1[p]=-1;tree2[p]=0;
		tag[p]=-1;
		cnt[p]=0;
		return;
	}
	int mid=l+r>>1;
	Push(p);
	if (pos<=mid){
		Del(p*2,l,mid,pos);
	}
	else{
		Del(p*2+1,mid+1,r,pos);
	}
	Pull(p);
}
void Ins(int p,int l,int r,int pos,LL val){
	if (l==r){
		cnt[p]=1;tree1[p]=val;tree2[p]=val;
		tag[p]=-1;return;
	}
	Push(p);
	int mid=l+r>>1;
	if (pos<=mid){
		Ins(p*2,l,mid,pos,val);
	}
	else{
		Ins(p*2+1,mid+1,r,pos,val);
	}
	Pull(p); 
}
void modify(int p,int l,int r,LL val){
	if (!cnt[p]) return;
	//cout<<"FUCK"<<' '<<l<<' '<<r<<' '<<val<<' '<<p<<' '<<tree2[p]<<endl;
	if (tree1[p]>=val){
		tag[p]=val;
		tree1[p]=val;
		tree2[p]=val*cnt[p];
		return;
	}
	if (l==r) return;
	Push(p);
	int mid=l+r>>1;
	if (cnt[p*2+1] && tree1[p*2+1]<=val){
		modify(p*2+1,mid+1,r,val);
	}
	else{
		modify(p*2+1,mid+1,r,val);
		modify(p*2,l,mid,val);
	}
	Pull(p);
//	cout<<"PULL"<<' '<<p<<' '<<tree2[p]<<endl;
} 
void Update(int i){
	if (i==1) return;
	int lp=i-1;
	int nc=ch[i];
	lp=fail[lp];
	while (lp){
		if (ch[lp+1]!=nc){
	//		cout<<"DELPOS"<<' '<<i-lp<<endl;
			Del(1,1,n,i-lp);
			___--;
			lp=fail[lp];
		}
		else{
			lp=lstU[lp];
		}
	}
	modify(1,1,n,w[i]);
	if (ch[i]==ch[1]){
	//	cout<<"FUCK"<<' '<<i<<' '<<w[i]<<endl;
		Ins(1,1,n,i,w[i]);
		___++;
	}

	//cout<<___<<' '<<B[i]<<endl;
	assert(___==B[i]);
}
const LL mod=1099511627776LL;
pair<LL,LL> DIV(LL X,LL Y){
	LL ret=(X/1000000)*(Y/1000000);
	LL rem=(X%1000000)*Y;
	rem+=(X/1000000*1000000)*(Y%1000000);
	ret+=rem/1000000000000LL;
	rem%=1000000000000;
	return mp(ret,rem);
}
void Out(LL X,LL Y){
	if (X==0){
		printf("%lld\n",Y);
		return;
	}
	pair<LL,LL> tmp=DIV(X,mod);
	tmp.second+=Y;
	tmp.first+=tmp.second/ 1000000000000LL;
	tmp.second%=1000000000000LL;
	printf("%lld%.12lld\n",tmp.first,tmp.second);
}
signed main(){
	B[0]=-1;
	for (int i=0;i<Maxn*4;i++) tag[i]=-1;
	scanf("%lld",&n);
	int __=(1<<30)-1;
	LL ansA=0,ansB=0,Mn=1e18;
	for (int i=1;i<=n;i++){
		LL cur=0;
		char tmp;
		scanf("%c",&tmp);
		if (tmp==' '||tmp=='\n') scanf("%c",&tmp);
		scanf("%lld",&w[i]);
		ch[i]=tmp-'a';
		ch[i]=(LL)(ch[i]+ansA%26*mod%26+ansB)%26;
		w[i]=w[i]^(ansB&__);
	//	printf("ADD %lld %lld\n",ch[i],w[i]);
		Gf(i);//cout<<"FF"<<' '<<fail[i]<<endl;
		Mn=min(Mn,(LL)w[i]);
		cur+=Mn;
		Update(i);
		cur+=tree2[1];
	//	cout<<"SHIT"<<' '<<tree2[1]<<endl;
		ansB+=cur;
		ansA+=ansB/mod;
		ansB%=mod;
		Out(ansA,ansB);
	}
	
	return ~~(0^_^0);
}
/*
4
a 1
b 2
a 3
b 4
*/