#include <cstdio>
#include <algorithm>
const int Maxn=10;
int f[1<<Maxn|5];
int a[Maxn+5];
int find_ans(){
	int sum_1=5,sum_2=5;
	int sc_1=0,sc_2=0;
	int turn=0;
	for(turn=1;sum_1+sc_1>=sc_2&&sum_2+sc_2>=sc_1&&turn<=10;turn++){
		if(a[turn-1]==1){
			if(turn&1){
				sc_1++;
			}
			else{
				sc_2++;
			}
		}
		if(turn&1){
			sum_1--;
		}
		else{
			sum_2--;
		}
	}
	return turn-1;
}
void init(){
	for(int i=0;i<(1<<Maxn);i++){
		for(int j=0;j<Maxn;j++){
			a[j]=(i>>j)&1;
		}
		f[i]=find_ans();
	}
}
char s[Maxn+5];
int work_dfs(int u,int mask=0){
	if(u>=10){
		return f[mask];
	}
	if(a[u]!=-1){
		return work_dfs(u+1,mask|(a[u]<<u));
	}
	else{
		return std::min(work_dfs(u+1,mask),work_dfs(u+1,mask|(1<<u)));
	}
}
void solve(){
	scanf("%s",s);
	for(int i=0;i<Maxn;i++){
		if(s[i]=='?'){
			a[i]=-1;
		}
		else{
			a[i]=s[i]-'0';
		}
	}
	printf("%d\n",work_dfs(0));
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}