#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define PER(i,a,b)for(int i=(b)-1,i##_end_=(a);i>=i##_end_;--i)
#define pb push_back
template<class T>inline bool umx(T& A,const T& B){return A<B?A=B,1:0;}
template<class T>inline bool umn(T& A,const T& B){return A>B?A=B,1:0;}
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;

const int maxn=20;
char s[maxn],t[maxn];
LL ns;
PIL res;
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%I64d",&ns);
	++ns;
//	itoa(ns,s,10);
	sprintf(s,"%I64d",ns);
	int n=strlen(s);
	res=PIL(0,0LL);
	REP(i,0,n){
		if(s[i]>'0'){
			REP(j,0,i)t[j]=s[j];
			t[i]=s[i]-1;
			REP(j,i+1,n)t[j]='9';
			
			int sum=0;
			REP(j,0,n)sum+=t[j]-'0';t[n]='\0';
			
			LL nt;sscanf(t,"%I64d",&nt);
			umx(res,PIL(sum,nt));
		}
	}
	printf("%I64d\n",res.second);
	return 0;
}