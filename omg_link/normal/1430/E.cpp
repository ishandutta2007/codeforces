#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MN 200000
typedef long long LL;

int n,b[MN+5];
LL ans=0;
char s[MN+5],t[MN+5];
std::vector<int> v[26];
int cnt[26];

int T[MN*4+5];

void modify(int k,int l,int r,int p){
	T[k]++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) modify(k<<1,l,mid,p);
	else modify(k<<1|1,mid+1,r,p);
}

int query(int k,int l,int r,int L,int R){
	if(L>R) return 0;
	if(l==L&&r==R) return T[k];
	int mid=(l+r)>>1;
	if(R<=mid) return query(k<<1,l,mid,L,R);
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	return query(k<<1,l,mid,L,mid)+query(k<<1|1,mid+1,r,mid+1,R);
}

int main(){
	scanf("%d%s",&n,&s[1]);
	for(int i=1;i<=n;i++)
		t[i] = s[n-i+1];
	for(int i=1;i<=n;i++)
		v[s[i]-'a'].push_back(i);
	for(int i=1;i<=n;i++)
		b[i] = v[t[i]-'a'][cnt[t[i]-'a']++];
	for(int i=1;i<=n;i++){
		ans += query(1,1,n,b[i]+1,n);
		modify(1,1,n,b[i]);
	}
	printf("%lld\n",ans);
}