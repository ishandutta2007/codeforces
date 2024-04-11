#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,tot=0;
queue<int> q;
int a[505],ansx[2500005],ansy[2500005];

int main(){
	scanf("%d",&n);
	int s=0,cnt=0,c=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i]; cnt+=(a[i]>=2); c+=(a[i]<2);
	}
	if(s<2*n-2){
		printf("NO\n");
		return 0;
	}
	int ans=cnt;
	if(c==0)
		ans--;
	else if(c>=2)
		ans++;
	printf("YES %d\n",ans);
	if(c==0){
		cout<<n-1<<endl;
		for(int i=1;i<=n-1;i++)
			printf("%d %d\n",i,i+1);
		return 0;
	}
	int lst=0,x=0,y=0;
	for(int i=1;i<=n;i++){
		if(a[i]<2){
			if(!x)
				x=i;
			else if(!y)
				y=i;
		}
	}
	lst=x;
	for(int i=1;i<=n;i++){
		if(a[i]>=2){
			ansx[++tot]=lst,ansy[tot]=i;
			lst=i;
			if(a[i]>2)q.push(i);
		}
	}
	if(y)
		ansx[++tot]=lst,ansy[tot]=y;
	int tmp;
	for(int i=1;i<=n;i++){
		if(a[i]<2&&i!=x&&i!=y){
			tmp=q.front();
			ansx[++tot]=i,ansy[tot]=tmp;
			a[tmp]--;
			if(a[tmp]==2)
				q.pop();
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}