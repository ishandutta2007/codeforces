#include<bits/stdc++.h>

using namespace std;

int n,ax,ay;
char a[200005];
int cnt[200005][10],ans;

void divide(int l,int r,int x){
	if(l>r)
		return;
	int mid=(l+r)/2;
	if(abs(cnt[n][1]-cnt[n][2]-cnt[mid][1]+cnt[mid][2]+cnt[x-1][1]-cnt[x-1][2]-ax)
		+abs(cnt[n][3]-cnt[n][4]-cnt[mid][3]+cnt[mid][4]+cnt[x-1][3]-cnt[x-1][4]-ay)<=mid-x+1){
		ans=mid;
		divide(l,mid-1,x);
	}
	else
		divide(mid+1,r,x);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>ax>>ay;
	for(int i=1;i<=n;i++){
		cnt[i][2]=cnt[i-1][2]+(a[i]=='L');
		cnt[i][1]=cnt[i-1][1]+(a[i]=='R');
		cnt[i][3]=cnt[i-1][3]+(a[i]=='U');
		cnt[i][4]=cnt[i-1][4]+(a[i]=='D');
	}
	if((cnt[n][1]+cnt[n][2]+cnt[n][3]+cnt[n][4]-ax-ay)%2==1){
		cout<<-1<<endl;
		return 0;
	}
	if(cnt[n][1]-cnt[n][2]-ax==0&&cnt[n][3]-cnt[n][4]-ay==0){
		cout<<0<<endl;
		return 0;
	}
	int ret=1<<20;
	for(int i=1;i<=n;i++){
		ans=1<<30;
		divide(i,n,i);
		ret=min(ret,ans-i+1);
	}
	if(ret==1<<20)
		cout<<-1<<endl;
	else
		cout<<ret<<endl;
	return 0;
}