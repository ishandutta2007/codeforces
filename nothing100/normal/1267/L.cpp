#include <bits/stdc++.h>
#define ft(i,a,b) for(int i=(a); i<=(b); ++i)
#define fd(i,a,b) for(int i=(a); i>=(b); --i)
#define fv(i,v) for(size_t i=0; i<(v).size(); ++i)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define OP operator
#define LB lower_bound
#define UB upper_bound
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int N=1005;
char s[N*N];
int a[26];
char ans[N][N];
int top[N];

int main(){
	int n,l,k;
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",s+1);
	for(int i=1; s[i]; ++i) a[s[i]-'a']++;
	
	int f=1;	
	ft(i,0,25){
		if (top[k]==l) break;
		int now=f;
		while (a[i] && top[k]<l){
			ans[now][++top[now]]='a'+i;
			a[i]--;
			now++;
			if (now>k) now=f;
		}
		while (top[f]>top[k]) f++;
		/*
		if (ok){
			while (a[i] && top<l){
				ans[++top]='a'+i;
				a[i]--;
			}
			continue;
		}
		// not ok
		int t=a[i]/k;
		if (a[i]%k) ok=true;
		while (t && top<l){
			
			ans[++top]='a'+i;
			t--;
		}
		continue;
		*/
	}
	
	int p=0;
	ft(i,1,n) while (top[i]<l){
		while (!a[p]) p++;
		ans[i][++top[i]]='a'+p;
		a[p]--;
	}	
	
	ft(i,1,n) printf("%s\n",ans[i]+1);
	//printf("%s\n",ans+1);
	return 0;
}