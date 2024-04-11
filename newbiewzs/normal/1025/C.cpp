#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=5e5+5;
int n;
char a[N];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++)a[i+n]=a[i];
	int mq=0,maxx=0;
	for(int i=1;i<=2*n;i++){
		if(a[i]==a[i-1]){
			mq=1;
		}
		else{
			mq++;
		}
		maxx=max(maxx,mq);
	}
	maxx=min(maxx,n);
	cout<<maxx;
	return 0;
}