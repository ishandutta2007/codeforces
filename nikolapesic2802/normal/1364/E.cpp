//Abusing TLE #5
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> val(2048,(1<<11)-1);
int x,y,n,c,cnt;
int ask(int a,int b){
	cnt++;
	if(cnt>4269)
		while(true); //This line
	printf("? %i %i\n",a+1,b+1);
	fflush(stdout);
	scanf("%i",&c);
	return c;
}
bool found(){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((val[i]&val[j])==0){
				x=i;
				y=j;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%i",&n);
	while(!found()){
		int aa=rng()%n,bb=rng()%n;
		while(bb==aa)
			bb=rng()%n;
		int v=ask(aa,bb);
		val[aa]&=v;
		val[bb]&=v;
	}
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		if(x!=i)
			a[i]=ask(x,i);
		if(y!=i)
			b[i]=ask(y,i);
	}
	vector<int> ans(n);
	for(int i=0;i<11;i++){
		if((val[x]&(1<<i))==0){
			for(int j=0;j<n;j++){
				if(j==x)
					continue;
				if(a[j]&(1<<i))
					ans[j]|=(1<<i);
			}
		}
		else{
			for(int j=0;j<n;j++){
				if(j==y)
					continue;
				if(b[j]&(1<<i))
					ans[j]|=(1<<i);
			}
		}
	}
	printf("! ");
	for(int i=0;i<n;i++)
		printf("%i ",ans[i]);
	printf("\n");
	return 0;
}