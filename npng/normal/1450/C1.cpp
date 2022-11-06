#include <cstdio>
const int Maxn=300;
const int Inf=0x3f3f3f3f;
int n;
char s[Maxn+5][Maxn+5];
int a[3][3];
void change(int mask){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			a[i][j]=(mask>>(i*3+j))&1;
		}
	}
}
bool check(){
	for(int i=0;i<3;i++){
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]){
			return 0;
		}
	}
	for(int j=0;j<3;j++){
		if(a[0][j]==a[1][j]&&a[1][j]==a[2][j]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	int num=0;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<n;j++){
			if(s[i][j]!='.'){
				num++;
			}
		}
	}
	for(int mask=0;mask<(1<<9);mask++){
		change(mask);
		if(!check()){
			continue;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='.'){
					continue;
				}
				if(a[i%3][j%3]==0&&s[i][j]=='X'){
					sum++;
				}
			}
		}
		if(sum<=num/3){
			break;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='.'){
				putchar('.');
				continue;
			}
			if(a[i%3][j%3]==0){
				putchar('O');
			}
			else{
				putchar('X');
			}
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}