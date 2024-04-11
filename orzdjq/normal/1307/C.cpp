#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=100005;
char s[Maxn];
LL cnt[26],ans[26][26];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++){
		int v=s[i]-'a';
		for(int j=0;j<26;j++){
			ans[v][j]+=cnt[j];
		}
		cnt[v]++;
	}
	LL res=0;
	for (int i=0;i<26;i++) res=max(res,cnt[i]);
	for (int i=0;i<26;i++){
		for (int j=0;j<26;j++) res=max(res,ans[i][j]);
	}
	printf("%lld\n",res);
	return 0;
}