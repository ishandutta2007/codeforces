#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k,s,ans=1<<30,N=500000;
int a[500005],cnt[500005],tmp[500005];
vector<int> v[500005];

int main(){
	m=readint(); k=readint(); n=readint(); s=readint();
	for(int i=1;i<=m;i++) a[i]=readint();
	for(int i=1;i<=s;i++) cnt[readint()]++;
	memcpy(tmp,cnt,sizeof(tmp));
	for(int i=1;i<=m;i++) v[a[i]].push_back(i);
	for(int i=1;i<=N;i++) if(cnt[i]>v[i].size()) return printf("-1\n"),0;
	int now=0,pl;
	for(int i=1;i<=N;i++) if(cnt[i]) now=max(now,v[i][cnt[i]-1]);
	for(int i=1;i<=m-k+1;i++){
//		cout<<"TEST "<<i<<' '<<now<<' '<<ans<<' '<<pl<<endl;
		if((i-1)%k==0&&now-i-k+1<ans) ans=now-i-k+1,pl=i;
		if(cnt[a[i]]) cnt[a[i]]++;
		if(cnt[a[i]]>v[a[i]].size()) break;
		if(cnt[a[i]]) now=max(now,v[a[i]][cnt[a[i]]-1]);
	}
//	cout<<"TEST "<<ans<<endl;
	if(ans<=0) return printf("0\n"),0;
	if(ans>m-n*k) return printf("-1\n"),0;
	else{
		printf("%d\n",ans);
		for(int i=pl;i<=m;i++){
			if(tmp[a[i]]) tmp[a[i]]--;
			else printf("%d ",i),ans--;
			if(ans==0) return printf("\n"),0;
		}
	}
	return 0;
}