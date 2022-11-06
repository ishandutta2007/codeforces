#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=5000;
int n;
int a[Maxn+5];
int dfs(int left,int right){
	if(left>right){
		return 0;
	}
	while(left<=right&&a[left]==0){
		left++;
	}
	if(left==right){
		return 1;
	}
	if(left>right){
		return 0;
	}
	int ans=right-left+1;
	int minn=a[left];
	for(int i=left;i<=right;i++){
		minn=min(minn,a[i]);
	}
	int tmp=minn;
	if(tmp>=ans){
		return ans;
	}
	for(int i=left;i<=right;i++){
		a[i]-=minn;
	}
	int last=left-1;
	for(int i=last+1;i<=right;i++){
		if(a[i]==0){
			tmp+=dfs(last+1,i-1);
			if(tmp>=ans){
				break;
			}
			last=i;
		}
	}
	if(a[right]!=0){
		tmp+=dfs(last+1,right);
	}
	return min(tmp,ans);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d\n",dfs(1,n));
	return 0;
}