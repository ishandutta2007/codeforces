#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b-1);i>=(a);i--)
#define fi first
#define se second
#define pb push_back 
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=(int)1e5+9;
char A[N],B[N];
int main()
{
	int T,k;
	cin>>T;
	while(T--){
		scanf("%s%s",A,B);
		int p1=0,p2=0,len1,len2;
		len1=strlen(A);
		len2=strlen(B);
		for(int i=len2-1;i>=0;i--){
			if(B[i]=='1')break;
			p1++;
		}
		for(int i=len1-1;i>=0;i--){
			if(A[i]=='1'&&p2>=p1)break;
			p2++;
		}
		//cout<<len2<<' '<<len1<<' '<<p2<<' '<<p1<<"PP\n";
		if(p2>=p1)printf("%d\n",p2-p1);
		else printf("0\n");
	}
}