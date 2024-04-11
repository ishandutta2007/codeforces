#include<bits/stdc++.h>
#define int long long
using namespace std;

stack<pair<int,int> >st;

const int maxn=500007;
int n;
int a[maxn],b[maxn],sum1[maxn],sum2[maxn],ret1[maxn],ret2[maxn];

void solve(int a[],int sum[],int fk[]){
	for (int i=1;i<=n;++i){
		int tot=1,ret=sum[i-1];
		while (st.size()&&st.top().first>=a[i]){
			tot+=st.top().second;
			ret-=st.top().second*st.top().first;
			st.pop();
		}
		st.push({a[i],tot});
		ret+=a[i]*tot;
		sum[i]=ret;
		fk[i]=fk[i-1]+a[i];
	}
	for (int i=1;i<=n;++i){
		fk[i]=fk[i]-sum[i];
	}
	while (st.size()) st.pop();
}

#undef int
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];		
	}
	for (int i=1;i<=n;++i){
		b[i]=a[n+1-i];
	}
	solve(a,sum1,ret1);
	solve(b,sum2,ret2);
	int idx=-1;
	for (int i=1;i<=n;++i){
		if (idx==-1||ret1[i]+ret2[n+1-i]<ret1[idx]+ret2[n+1-idx]) idx=i;
	}
	long long mn=1e9;
	for (int i=idx;i>0;--i){
		mn=min(mn,a[i]);
		b[i]=mn;
	}
	mn=1e9;
	for (int i=idx;i<=n;++i){
		mn=min(mn,a[i]);
		b[i]=mn;
	}
	for (int i=1;i<=n;++i) cout<<b[i]<<" ";
}