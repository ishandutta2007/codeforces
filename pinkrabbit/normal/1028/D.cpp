#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int INF=0x3f3f3f3f;
#define Luogu GuGuGuGu
int s[400001],t;
set<int> st1,st2;
set<int>::iterator it;

int n;
char str[10];
int Ans=1;

int main(){
	scanf("%d",&n);
	st1.insert(-INF);
	st2.insert(INF);
	int P=0;
	F(i,1,n){
		int p;
		scanf("%s%d",str,&p);
		if(str[1]=='D'){
			it=st1.end(); --it;
			int bm=*it;
			it=st2.begin();
			int sm=*it;
			if(p<bm) st1.insert(p);
			else if(p>sm) st2.insert(p);
			else s[++t]=p;
		}
		else{
			it=st1.end(); --it;
			if(p<*it) return 0*puts("0");
			it=st2.begin();
			if(p>*it) return 0*puts("0");
			while(t) {
				if(s[t]==p) Ans=(Ans+Ans)%1000000007;
				else if(s[t]<p) st1.insert(s[t]);
				else st2.insert(s[t]);
				--t;
			}
			st1.erase(p); st2.erase(p);
		}
	}
	Ans=(LL)Ans*(t+1)%1000000007;
	printf("%d",Ans);
	return 0;
}