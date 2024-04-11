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
const int Maxn=1005;
char s[Maxn];
vector<int> A,B;
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++){
		if (s[i]=='(') A.pb(i);
		else B.pb(i);
	}
	reverse(B.begin(),B.end());
	int rs=-1;
	for (int i=0;i<min(A.size(),B.size());i++){
		if (A[i]<B[i]) rs=i;
	}
	vector<int> P;
	for (int i=0;i<=rs;i++) P.pb(A[i]),P.pb(B[i]);
	if (P.empty()){
		printf("0\n");return 0;
	}
	sort(P.begin(),P.end());
	printf("1\n%d\n",P.size());for (int i=0;i<P.size();i++) printf("%d ",P[i]+1);
	printf("\n");
}