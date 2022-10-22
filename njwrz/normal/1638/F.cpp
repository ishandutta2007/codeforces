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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,h[10005];
int vall[10005],valr[10005];
int l[10005],r[10005];
int pos1[10005],len1,pos2[10005],len2;
signed main(){
//	freopen("in.txt", "r", stdin);
//	freopen("1.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>h[i];
	FOR(i,1,n){
		gmax(vall[i],vall[i-1]);
		gmax(vall[i],h[i]);
		int mini=h[i];
		FOR(j,i+1,n){
			gmin(mini,h[j]);
			gmax(vall[j],mini*(j-i+1));
		}
	}
	for(int i=n;i>=1;i--){
		gmax(valr[i],valr[i+1]);
		gmax(valr[i],h[i]);
		int mini=h[i];
		for(int j=i-1;j>=1;j--){
			gmin(mini,h[j]);
			gmax(valr[j],mini*(i-j+1));
		}
	}
	int ans=0;
	FOR(i,0,n)gmax(ans,vall[i]+valr[i+1]);
	stack<int> st;
	FOR(i,1,n){
		while(!st.empty()&&h[st.top()]>=h[i])st.pop();
		if(!st.empty())l[i]=st.top()+1;else l[i]=1;
		st.emplace(i);
	} 
	while(!st.empty())st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&h[st.top()]>=h[i])st.pop();
		if(!st.empty())r[i]=st.top()-1;else r[i]=n;
		st.emplace(i);
	}
	FOR(i,1,n){
		FOR(j,l[i],r[i])if(l[j]>=l[i]&&r[j]<=r[i]){
			gmax(ans,h[i]*(r[i]-l[i]+1)+(h[j]-h[i])*(r[j]-l[j]+1));
		}
	}
	FOR(i,1,n)if(l[i]>1&&r[i]<n){
		len1=len2=0;
		int mini=1e18;
		for(int j=l[i]-1;j>=1;j--){
			gmin(mini,h[j]);
			if(mini==h[j])pos1[++len1]=j;
		}
		mini=1e18;
		FOR(j,r[i]+1,n){
			gmin(mini,h[j]);
			if(mini==h[j])pos2[++len2]=j;
		}
		int it=len2,val=0;
		pos2[len2+1]=n+1;pos1[len1+1]=0; 
		FOR(j,1,len1){
			while(it>0&&h[pos2[it]]+h[pos1[j]]<=h[i]){
				gmax(val,(pos2[it+1]-l[i])*h[pos2[it]]),it--;	
			}
			gmax(ans,(r[i]-pos1[j+1])*h[pos1[j]]+val);
		}
		it=len2;
		FOR(j,1,len1){
			while(it>0&&h[pos2[it]]+h[pos1[j]]<h[i]){
				it--;	
			}
			if(it)gmax(ans,(r[i]-pos1[j+1])*h[pos1[j]]+(pos2[it+1]-l[i])*(h[i]-h[pos1[j]]));
		}
		it=len1;
		FOR(j,1,len2){
			while(it>0&&h[pos1[it]]+h[pos2[j]]<h[i]){
				it--;
			}
			if(it)gmax(ans,(pos2[j+1]-l[i])*h[pos2[j]]+(r[i]-pos1[it+1])*(h[i]-h[pos2[j]]));
		}
	}
	cout<<ans;
	RE 0;
}