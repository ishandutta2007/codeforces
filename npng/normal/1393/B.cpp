#include <cstdio>
const int Maxn=100000;
int n,q;
int a[Maxn+5];
int num[Maxn+5];
int num_4,num_2;
void add(int x){
	if(num[x]%4==3){
		num[x]++;
		num_2--;
		num_4++;
	}
	else{
		if(num[x]%2==1){
			num[x]++;
			num_2++;
		}
		else{
			num[x]++;
		}
	}
}
void del(int x){
	if(num[x]%4==0){
		num[x]--;
		num_4--;
		num_2++;
	}
	else{
		if(num[x]%2==0){
			num[x]--;
			num_2--;
		}
		else{
			num[x]--;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i]);
	}
	scanf("%d",&q);
	while(q--){
		char op[5];
		scanf("%s",op);
		int x;
		scanf("%d",&x);
		if((*op)=='+'){
			add(x);
		}
		else{
			del(x);
		}
		if(num_4>=2||(num_4>=1&&num_2>=2)){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}