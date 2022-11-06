#include <bits/stdc++.h>
 
#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif
using namespace std;
const long long MAX=1e18;
vector<int> P;
vector<long long> Q;
bool chk[700];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long m=1, v, rep;
	int T;
	for(int i=2;i<700;i++) {
		if(!chk[i]) P.push_back(i);
		for(int j=0;j<P.size() && i*P[j]<700;j++) {
			chk[i*P[j]]=true;
			if(i%P[j]==0) break;
		}
	}
	for(auto p: P) {
		if(m>=MAX/p) {
			Q.push_back(m);
			m=1;
		}
		m*=p;
	}
	if(m>1){
		Q.push_back(m);
	}
	for(cin>>T;T--;) {
		long long ans=0;
		m=1;
		for(int i=0;i<10;i++) {
			cout<<"? "<<Q[i]<<endl;
			cin>>rep;
			m*=rep;
		}
		while(1){
			v=m*m;
			cout<<"? "<<v<<endl;
			cin>>rep;
			if(rep==m){
				break;
			}
			m=rep;
		}
		if(m<30){
			for(int i=10;i<Q.size();i++) {
				cout<<"? "<<Q[i]<<endl;
				cin>>rep;
				m*=rep;
			}
		}
		for(int i=1;1LL*i*i<=m;i++) {
			if(m%i==0) ans+=1+(1LL*i*i!=m);
		}
		cout<<"! "<<max(2*ans,8LL)<<endl;
	}
	return 0;
}