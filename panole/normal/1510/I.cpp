#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define PB push_back
using namespace std;
int n,m;
int WA[1050];
int a[10500];
int b[10500];
char s[1050],t[5];
double RNG(){
	double v=0;
	For(i,1,100) v=(v+rand()%2)/2;
	return v;
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%s",s+1);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int mx=0;
		For(j,1,n){
			if (s[j]=='0')
				++a[10000-WA[j]];
			else ++b[10000-WA[j]];
			mx=max(mx,10000-WA[j]);
		}
		double s1=0,s2=0;
		Rep(i,mx+50,mx-50){
			s1=s1*1.5+a[i];
			s2=s2*1.5+b[i];
		}
		s1=max(s1,1.0);
		s2=max(s2,1.0);
		int sgn=(RNG()>(s1/(s1+s2)));
		s[n+1]=(sgn?'1':'0');
		putchar(s[n+1]);
		puts("");
		fflush(stdout);
		scanf("%s",t+1);
		For(j,1,n+1) if (t[1]!=s[j]) ++WA[j];
	}
}
/*
1.5^1000
2^1000 
*/