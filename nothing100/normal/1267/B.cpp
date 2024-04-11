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

const int N=300050;
char s[N];

int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int i=1, j=n;
	while (true){
		if (s[i]!=s[j]){
			printf("0\n");
			return 0;
		}
		int ti=i, tj=j;
		while (s[ti+1]==s[ti]) ti++;
		if (ti==j){
			if (j-i+1>=2) printf("%d\n",j-i+2);
				else printf("0\n");
			return 0;
		}
		while (s[tj-1]==s[tj]) tj--;
		int sum=(ti-i+1)+(j-tj+1);
		if (sum<3){
			printf("0\n");
			return 0;
		}
		i=ti+1;
		j=tj-1;
	}
	return 0;
}