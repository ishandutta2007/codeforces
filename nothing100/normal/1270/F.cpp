#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;
const int mo=5000011;
LL ans;
char ch[200020];
int l,nxt[200020],f[200020];
vector<pair<int,int>> ha[5000011];
int main(){
	scanf("%s",ch);
	l=strlen(ch);
	ch[l]='1';
	for (int i=0;i<l;i++) f[i]=ch[i]-'0';
	for (int i=1;i<l;i++) f[i]=f[i]+f[i-1];
	for (int i=l-1;i>=0;i--){
		if (ch[i+1]=='1') nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	for (int i=1;i<300;i++){
		ha[0].push_back(make_pair(0,1));
		for (int j=0;j<l;j++){
			int tmp=j+1-i*f[j],hav=0;
			tmp=tmp%mo;
			if (tmp<0) tmp+=mo;
			for (int k=0;k<ha[tmp].size();k++)
			if (ha[tmp][k].fi==j+1-i*f[j]){
				ans+=ha[tmp][k].se;
				ha[tmp][k].se++;
				hav=1;
				break;
			}
			if (!hav) ha[tmp].push_back(make_pair(j+1-i*f[j],1));
		}
		for (int j=0;j<l;j++){
			int tmp=j+1-i*f[j];
			tmp=tmp%mo;
			if (tmp<0) tmp+=mo;
			ha[tmp].clear();
		}
	}
	for (int i=0;i<l;i++){
		int now=i;
		int sum=ch[i]-'0';
		while (now!=l&&sum<=l/300){
			if (sum)
				ans+=max(0,(nxt[now]-i)/sum-max((now-i)/sum,299));
			now=nxt[now];
			sum++;
		}
	}
	printf("%lld\n",ans);
}