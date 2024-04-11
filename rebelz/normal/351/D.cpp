#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int block;

struct node{
	int id,l,r;
	bool operator<(const node c)const{
		if(l/block==c.l/block) return l/block==0?r<c.r:r>c.r;
		return l/block<c.l/block;
	}
}q[100005];

int n,m,nl=1,nr=0,now,can;
int lst[100005],nxt[100005],a[100005],ap[100005],num[100005],cnt[100005],ans[100005];
unordered_map<int,int> mp[100005];

void add(int x,int g){
	if(!g){
		if(!nxt[x]||nxt[x]>nr) now++,can++;
		else{
			int tmp=num[a[x]];
			if(cnt[a[x]]==1) mp[a[x]][nxt[x]-x]=1,num[a[x]]++;
			else if(mp[a[x]][nxt[x]-x]==0) mp[a[x]][nxt[x]-x]=1,num[a[x]]++;
			else mp[a[x]][nxt[x]-x]++;
			if(tmp==1&&num[a[x]]==2) can--;
		}
	}
	else{
		if(!lst[x]||lst[x]<nl) now++,can++;
		else{
			int tmp=num[a[x]];
			if(cnt[a[x]]==1) mp[a[x]][x-lst[x]]=1,num[a[x]]++;
			else if(mp[a[x]][x-lst[x]]==0) mp[a[x]][x-lst[x]]=1,num[a[x]]++;
			else mp[a[x]][x-lst[x]]++;
			if(tmp==1&&num[a[x]]==2) can--;
		}
	}
	cnt[a[x]]++;
}

void del(int x,int g){
	if(!g){
		if(!nxt[x]||nxt[x]>nr) now--,can--;
		else{
			int tmp=num[a[x]];
			if(cnt[a[x]]==2) mp[a[x]][nxt[x]-x]=0,num[a[x]]--;
			else if(mp[a[x]][nxt[x]-x]==1) mp[a[x]][nxt[x]-x]=0,num[a[x]]--;
			else mp[a[x]][nxt[x]-x]--;
			if(tmp==2&&num[a[x]]==1) can++;
		}
	}
	else{
		if(!lst[x]||lst[x]<nl) now--,can--;
		else{
			int tmp=num[a[x]];
			if(cnt[a[x]]==2) mp[a[x]][x-lst[x]]=0,num[a[x]]--;
			else if(mp[a[x]][x-lst[x]]==1) mp[a[x]][x-lst[x]]=0,num[a[x]]--;
			else mp[a[x]][x-lst[x]]--;
			if(tmp==2&&num[a[x]]==1) can++;
		}
	}
	cnt[a[x]]--;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	block=sqrt(n);
	for(int i=1;i<=n;i++){
		lst[i]=ap[a[i]],nxt[ap[a[i]]]=i;
		ap[a[i]]=i;
	}
	m=readint();
	for(int i=1;i<=m;i++) q[i].l=readint(),q[i].r=readint(),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++){
		while(q[i].l<nl) add(--nl,0);
		while(q[i].r>nr) add(++nr,1);
		while(q[i].l>nl) del(nl++,0);
		while(q[i].r<nr) del(nr--,1);
		ans[q[i].id]=now-(bool)can+1;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}