#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

constexpr int border=1000;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	scanf("%lld %lld",&N,&M);
	vector<vector<int>>edge(N);
	vector<set<int>>st_edge(N);
	vector<long long int>in(N);
	vector<long long int>out(N);
	set<pair<int ,int>>st;
	vector<int>gain(N);
	for(int i=0;i<N;i++){
		st.insert({i-N,i});
		gain[i]=i-N;
	}
	for(int i=0;i<M;i++){
		scanf("%lld %lld",&L,&R);
		L--;
		R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
		st_edge[L].insert(R);
		st_edge[R].insert(L);
		if(L>R)swap(L,R);
		in[L]++;
		out[R]++;
	}
	long long int ans=0;
	for(int i=0;i<N;i++){
		ans+=in[i]*out[i];
	}
	printf("%lld\n",ans);
	cin>>K;
	for(int i=0;i<K;i++){
		int num;
		scanf("%d",&num);
		num--;
		if(edge[num].size()<=border){
			ans-=in[num]*out[num];
			for(auto j:edge[num]){
				if(gain[j]>gain[num]){
					ans-=in[j]*out[j];
					out[j]--;
					in[j]++;
					ans+=in[j]*out[j];
				}
			}
			in[num]=0;
			out[num]=edge[num].size();
			//ans+=in[num]*out[num];
			st.erase({gain[num],num});
			gain[num]=i;
			st.insert({gain[num],num});
		}
		else{
			auto it=st.upper_bound({gain[num],num});
			ans-=in[num]*out[num];
			while(it!=st.end()){
				if(st_edge[num].find(it->second)!=st_edge[num].end()){
					ans-=out[it->second]*in[it->second];
					out[it->second]--;
					in[it->second]++;
					ans+=out[it->second]*in[it->second];
				}
				it=next(it);
			}
			in[num]=0;
			out[num]=edge[num].size();
			st.erase({gain[num],num});
			gain[num]=i;
			st.insert({gain[num],num});
		}
		printf("%lld\n",ans);
	}
	return 0;
}