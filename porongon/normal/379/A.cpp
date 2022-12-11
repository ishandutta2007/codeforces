#include <bits/stdc++.h>
#define fore(i,a,n) for(int i=a,qwer=n;i<qwer;i++)
#define pb push_back
#define snd second
#define fst first
#define mp make_pair
using namespace std;

typedef long long ll;


typedef pair<int,int> ii;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int c=0,ans=0;
	while(a) {
		ans++;
		a--;
		c++;
		if(c==b) {
			c=0;
			a++;
		}
	}
	printf("%d\n",ans);
}