/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int c1,c2,c3;
int m1[300005],m2[300005],cnt1,cnt2,sum1[300005],sum2[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>c3;
	int q;
	cin>>q;
	FOR(i,1,q){
		int x;
		string s;
		cin>>x>>s;
		if(s[0]=='U'){
			m1[++cnt1]=x;
		}else m2[++cnt2]=x;
	}
	sort(m1+1,m1+cnt1+1);
	sort(m2+1,m2+cnt2+1);
	FOR(i,1,cnt1)sum1[i]=sum1[i-1]+m1[i];
	FOR(i,1,cnt2)sum2[i]=sum2[i-1]+m2[i];
	bool f1=cnt1>c1,f2=cnt2>c2;
	if(!f1&&!f2){
		cout<<cnt1+cnt2<<' '<<sum1[cnt1]+sum2[cnt2];RE 0;
	}else if(!f1&&f2){
		cout<<cnt1+min(cnt2,c2+c3)<<' '<<sum1[cnt1]+sum2[min(cnt2,c2+c3)];
	}else if(f1&&!f2){
		cout<<min(cnt1,c1+c3)+cnt2<<' '<<sum1[min(cnt1,c1+c3)]+sum2[cnt2];
	}else{
		int max1=0,max2=0;
		FOR(i,0,c3){
			int t1=min(cnt1,c1+i),t2=min(c2+c3-i,cnt2);
			if(t1+t2>max1){
				max1=t1+t2;
				max2=sum1[t1]+sum2[t2];
			}else if(t1+t2==max1&&sum1[t1]+sum2[t2]<max2){
				max2=sum1[t1]+sum2[t2];
			}
		}
		cout<<max1<<' '<<max2;
	}
	RE 0;
}