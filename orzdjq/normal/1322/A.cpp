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
const int Maxn=1000005;
char c[Maxn];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",c);
	int cnt=0;
	for (int i=0;i<n;i++){
		if (c[i]=='(') cnt++;
		else cnt--;
	}
	if (cnt!=0){
		printf("-1\n");
		return 0;
	}
	int ans=0;
	for (int i=0;i<n;i++){
		if (c[i]=='(') cnt++;
		else cnt--;
		if (cnt==-1){
			int J;
			for (int j=i+1;;j++){
				if (c[j]=='(') cnt++;
				else cnt--;
				if (cnt==0){
					J=j;
					break; 
				}
			}
			ans+=J-i+1;
			i=J;
		}
	}
	printf("%d\n",ans);
	return 0;
}