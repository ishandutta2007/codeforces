#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=1e6+5;
char c[Maxn];
int n;
int s[Maxn],p[Maxn];
int main(){
	scanf("%s",c);
	n=strlen(c);
	for (int i=1;i<n;i++){
		p[i]=p[i-1]+(c[i]=='v' && c[i-1]=='v');
	}
	for (int i=n-2;i>=0;i--){
		s[i]=s[i+1]+(c[i]=='v' && c[i+1]=='v');
	}
	LL ans=0;
	for (int i=1;i<n-1;i++){
		if (c[i]=='o') ans+=1ll*p[i-1]*s[i+1];
	}
	printf("%I64d\n",ans);
	return 0;
}