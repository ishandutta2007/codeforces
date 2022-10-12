#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;
using pi=pair<int,int>;

int main(){
	int n,k;
	cin >> n >> k;
	int d=(n+1);
	vector<int> l(k+1),r(k+1);
	for(int i=0;i<k;i++){cin >> l[i] >> r[i];}
	l[k]=2*n;r[k]=2*n;
	vector<int> dp(2*(n+1),inf);
	dp[0]=0;
	for(int i=0;i<k;i++){
		vector<int> ndp(2*(n+1),inf);
		vector<pi> vp;
		int lg=l[i+1]-l[i];
		int sm=l[i+1]-r[i];
		for(int j=0;j<(n+1);j++){
			if(dp[j]==inf){continue;}
			//0flip
			ndp[j]=min(ndp[j],dp[j]);
			//1flip
			vp.push_back({d+min(j+sm,d),dp[j]+1});
			vp.push_back({d+min(j+lg+1,d),-(dp[j]+1)});
			//2flip
			vp.push_back({min(j,d),dp[j]+2});
			vp.push_back({min(j+lg-sm+1,d),-(dp[j]+2)});
		}
		for(int j=(n+1);j<2*(n+1);j++){
			if(dp[j]==inf){continue;}
			//0flip
			if((j+lg)<2*(n+1)){
				ndp[j+lg]=min(ndp[j+lg],dp[j]);
			}
			//1flip
			vp.push_back({min(j,2*d)-d,dp[j]+1});
			vp.push_back({min(j+lg-sm+1,2*d)-d,-(dp[j]+1)});
			//2flip
			vp.push_back({min(j+sm,2*d),dp[j]+2});
			vp.push_back({min(j+lg+1,2*d),-(dp[j]+2)});
		}
		sort(vp.begin(),vp.end());
		vp.push_back({inf,inf});
		multiset<int> st;
		int pt=0;
		for(int i=0;i<2*(n+1);i++){
			while(vp[pt].first<=i){
				int ss=vp[pt].second;
				if(ss>0){st.insert(ss);}
				else{st.erase(st.find(-ss));}
				pt++;
			}
			if(!st.empty()){
				int tg=(*st.begin());
				ndp[i]=min(ndp[i],tg);
			}
			//cout << ndp[i] << ' ';
		}//cout << '\n';
		dp.swap(ndp);
	}
	int res=min(dp[d-1],dp[2*d-1]);
	if(res==inf){cout << "Hungry\n";}
	else{
		cout << "Full\n";
		cout << res << '\n';
	}
  return 0;
}