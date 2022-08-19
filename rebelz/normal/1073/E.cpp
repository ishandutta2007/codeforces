#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll cys=998244353;

struct node{
	ll sum,t;
}d[20][2000][2][2];

ll l,r,k;
ll b[20];

ll solve(ll x){
	memset(d,0,sizeof(d));
	ll len=0;
	for(;x;b[++len]=x%10,x/=10);
	reverse(b+1,b+len+1);
	d[0][0][1][1].sum=0,d[0][0][1][1].t=1;
	ll tmp;
	for(int i=0;i<=len-1;i++)
		for(int j=0;j<=1023;j++)
			for(int c=0;c<=1;c++)
				for(int l=0;l<=1;l++)
					for(int num=0;num<=(c?b[i+1]:9);num++){
						if(l==1&&num>0)
							tmp=1<<num;
						else if(l==1&&num==0)
							tmp=0;
						else
							tmp=j|(1<<num);
						d[i+1][tmp][c&(num==b[i+1])][l&(num==0)].sum=(d[i+1][tmp][c&(num==b[i+1])][l&(num==0)].sum+d[i][j][c][l].sum*10%cys+d[i][j][c][l].t%cys*num%cys)%cys;
						d[i+1][tmp][c&(num==b[i+1])][l&(num==0)].t+=d[i][j][c][l].t;
					}
	ll cnt=0,ans=0;
	for(int i=0;i<=1023;i++){
		tmp=i,cnt=0;
		for(;tmp;tmp&=(tmp-1),cnt++);
		if(cnt<=k)
			ans=(ans+d[len][i][0][0].sum+d[len][i][0][1].sum+d[len][i][1][0].sum+d[len][i][1][1].sum)%cys;
	}
	return ans;
}

int main(){
	cin>>l>>r>>k;
	cout<<(solve(r)-solve(l-1)+cys)%cys<<endl;
	return 0;
}