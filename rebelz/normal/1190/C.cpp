#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
char s[100005];
int cnt0[100005],cnt1[100005],mx0[100005],mx1[100005],mn0[100005],mn1[100005];

int main(){
	n=readint(); k=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) cnt0[i]=cnt0[i-1]+(s[i]=='0');
	for(int i=1;i<=n;i++) cnt1[i]=i-cnt0[i];
	for(int i=1;i<=n;i++){
		mx0[i]=mx0[i-1],mx1[i]=mx1[i-1];
		if(s[i]=='0') mx0[i]=i;
		else mx1[i]=i;
	}
	mn0[n+1]=mn1[n+1]=n+1;
	for(int i=n;i>=1;i--){
		mn0[i]=mn0[i+1],mn1[i]=mn1[i+1];
		if(s[i]=='0') mn0[i]=i;
		else mn1[i]=i;
	}
	for(int i=1;i<=n-k+1;i++){
		if(cnt0[i-1]==i-1&&cnt0[n]-cnt0[i+k-1]==n-i-k+1) return printf("tokitsukaze\n"),0;
		if(cnt1[i-1]==i-1&&cnt1[n]-cnt1[i+k-1]==n-i-k+1) return printf("tokitsukaze\n"),0;
	}
	for(int i=1;i<=n-k+1;i++){
		if(cnt0[i-1]>0&&cnt0[n]-cnt0[i+k-1]>0) return printf("once again\n"),0;
		if(cnt1[i-1]>0&&cnt1[n]-cnt1[i+k-1]>0) return printf("once again\n"),0;
	}
	for(int i=1;i<=n-k+1;i++){
		if(cnt0[i-1]>0&&cnt0[n]-cnt0[i+k-1]==0&&mx0[i-1]-mn0[1]+1>k) return printf("once again\n"),0;
		if(cnt0[i-1]==0&&cnt0[n]-cnt0[i+k-1]>0&&mx0[n]-mn0[i+k]+1>k) return printf("once again\n"),0;
		if(cnt1[i-1]>0&&cnt1[n]-cnt1[i+k-1]==0&&mx1[i-1]-mn1[1]+1>k) return printf("once again\n"),0;
		if(cnt1[i-1]==0&&cnt1[n]-cnt1[i+k-1]>0&&mx1[n]-mn1[i+k]+1>k) return printf("once again\n"),0;
	}
	printf("quailty\n");
	return 0;
}