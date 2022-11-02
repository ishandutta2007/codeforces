#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<cmath>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
//#define int long long
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N];
struct dagengengengnengendui{
	priority_queue<int>hp,dl;
	void push(int x){hp.push(x);}
	void del(int x){dl.push(x);while(dl.size()&&dl.top()==hp.top())dl.pop(),hp.pop();}
	int mx(){while(dl.size()&&dl.top()==hp.top())dl.pop(),hp.pop();return hp.size()?hp.top():-1;} 
	int sze(){return hp.size()-dl.size();}
}hp;
int pra[N],sua[N],prm[N],sun[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1])pra[i]=pra[i-1]+1;
		else pra[i]=1;
		sun[i]=max(sun[i-1],pra[i]);
	}
	for(int i=n;i>=1;i--){
		if(a[i]>a[i+1])sua[i]=sua[i+1]+1;
		else sua[i]=1;
		prm[i]=max(prm[i-1],sua[i-1]);
	}
	for(int i=1;i<=n;i++){
		sun[i]=max(sun[i-1],max(pra[i],sua[i]));
		
	}
	for(int i=1;i<=n;i++)hp.push(pra[i]),hp.push(sua[i]);
	int cnt=0;
	int ps=0;
	for(int i=1;i<=114511;i++){
		ps++;
	}
	for(int i=1;i<=n;i++)
	{
	if(pra[i] and sua[i]){
		hp.del(pra[i]),hp.del(sua[i]);
		if(hp.mx()>=max(pra[i],sua[i]));
		else{
			int maxx=max(pra[i],sua[i]),minn=min(pra[i],sua[i]);
			if(maxx%2==0);
			else cnt+=(maxx-1<minn);
		}
		hp.push(pra[i]),hp.push(sua[i]);
	}
	int gg=0;
	for(int k=1;k<=10;k++){
		gg++;
	}
}
	cout<<cnt;
	return 0;
}