#include <bits/stdc++.h>
using namespace std;
const int Maxn=3000;
int p[Maxn+5];
int query(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	srand(time(0));
	int n;
	scanf("%d",&n);
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	random_shuffle(v.begin(),v.end());
	int a=v[0],b=v[1],val=query(a,b);
	for(int i=2;i<n;i++){
		int tmp=query(b,v[i]);
		if(tmp<val){
			a=v[i];
			val=tmp;
		}
		else if(tmp==val){
			b=v[i];
			val=query(a,v[i]);
		}
	}
	int id;
	while(1){
		int i=rand()%n+1;
		if(i==a||i==b){
			continue;
		}
		int t1=query(i,a),t2=query(i,b);
		if(t1!=t2){
			id=(t1<t2?a:b);
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=id){
			p[i]=query(i,id);
		}
	}
	printf("!");
	for(int i=1;i<=n;i++){
		printf(" %d",p[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
}