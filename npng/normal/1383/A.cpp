#include <cstdio>
#include <cstring>
const int Maxn=100000;
int n;
char a[Maxn+5],b[Maxn+5];
bool mp[26][26];
int arrive[26];
int count(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
bool work(){
	for(int i=0;i<20;i++){
		arrive[i]=0;
		for(int j=0;j<20;j++){
			if(mp[j][i]){
				arrive[i]|=(1<<j);
			}
		}
	}
	for(int i=0;i<20;i++){
		for(int j=i+1;j<20;j++){
			if((arrive[i]&arrive[j])>0){
				mp[i][j]=1;
				for(int k=0;k<20;k++){
					if(mp[k][i]&&mp[k][j]){
						mp[k][j]=0;
					}
				}
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		bool flag=1;
		memset(mp,0,sizeof mp);
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]){
				flag=0;
				break;
			}
		}
		if(!flag){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			mp[a[i]-'a'][b[i]-'a']=1;
		}
		for(int i=0;i<20;i++){
			mp[i][i]=0;
		}
		while(work());
		int ans=0;
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				if(mp[i][j]){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}