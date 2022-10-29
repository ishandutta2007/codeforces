#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define lb(x) ((x)&(-x))
using namespace std;
const int N=1e5+9;
const int pp=998244353;
const int mod=1e9+7;
int a[101],num1[101],num2[101],cnt1,cnt2,head1,head2,tail1,tail2; 
int main()
{
	int n;
	cin>>n;
	int last=0,ans=0;
	int p1=n/2,p2=n/2;
	if(n&1)++p1;
	rep(i,1,n+1){
		cin>>a[i];
		if(a[i]){
			if(a[i]&1)--p1;
			else --p2;
			if(i-last-1){
				if(!last){
					if(a[i]&1)head1=i-last-1;
					else head2=i-last-1;
				}
				else{
					if((a[i]+a[last])&1)++ans;
					else{
						if(a[i]&1)num1[cnt1++]=i-last-1;
						else num2[cnt2++]=i-last-1;
					}
				}
			}
			last=i;
			if(a[i-1]&&((a[i-1]+a[i])&1))++ans;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(last<n){
		if(a[last]&1)tail1=n-last;
		else tail2=n-last;
	}
	sort(num1,num1+cnt1);
	sort(num2,num2+cnt2);
	rep(i,0,cnt1){
		if(p1>=num1[i]){
			p1-=num1[i];
		}
		else ans+=2;
	}
	rep(i,0,cnt2){
		if(p2>=num2[i]){
			p2-=num2[i];
		}
		else ans+=2;
	}
	if(head1){
		if(p1<head1)++ans;
		else p1-=head1;
	}
	if(head2){
		if(p2<head2)++ans;
		else p2-=head2;
	}
	if(tail1){
		if(p1<tail1)++ans;
		else p1-=tail1;
	}
	if(tail2){
		if(p2<tail2)++ans;
		else p2-=tail2;
	}
	cout<<ans;
}
/*
12
0 2 3 5 4 0 0 6 7 9 8 0
11
0 2 0 0 8 4 10 5 7 9 11
*/