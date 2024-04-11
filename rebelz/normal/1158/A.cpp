#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,ans;
ll a[100005],b[100005],cnt[100005];
set<pair<int,int> > s;

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]>b[1]) return printf("-1\n"),0;
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	ans+=sum*m;
	for(int i=1;i<=n;i++) s.insert(mp(a[i],i));
	for(int i=1;i<=m;i++){
		auto it=s.upper_bound(mp(b[i],1<<30)); it--;
		ans+=b[i]-it->fi;
		if(b[i]!=it->fi) cnt[it->se]++;
		if(cnt[it->se]==m-1) s.erase(it);
	}
	cout<<ans<<endl;
	return 0;
}