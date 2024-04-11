#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n;
int arr[200007],tot,cnt;
char str[200007];
vector<int> ans[200007];
set<int> st1,st2;
set<int>::iterator iter;

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	F(i,1,n) if(str[i]=='0') st1.insert(i); else st2.insert(i);
	while(!st1.empty()){
		++tot;
		int lst=*st1.lower_bound(0);
		st1.erase(lst);
		ans[tot].push_back(lst);
		while(1){
			int tmp1,tmp2;
			iter=st2.lower_bound(lst);
			if(iter==st2.end()) break;
			tmp1=*iter;
			iter=st1.lower_bound(tmp1);
			if(iter==st1.end()) break;
			tmp2=*iter;
			st2.erase(tmp1), st1.erase(tmp2);
			ans[tot].push_back(tmp1);
			ans[tot].push_back(tmp2);
			lst=tmp2;
		}
	}
	if(!st2.empty()){puts("-1"); return 0;}
	printf("%d\n",tot);
	F(i,1,tot){
		printf("%d ",ans[i].size());
		F2(j,0,ans[i].size()) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}