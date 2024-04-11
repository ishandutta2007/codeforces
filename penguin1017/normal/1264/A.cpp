#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std; 
const int N=4e5+9;
int p[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,1,n+1)scanf("%d",&p[i]);
		p[0]=-1;
		p[n+1]=-1;
		if(n<=5){
			printf("0 0 0\n");
			continue;
		}
		int pos=n/2;
		while(pos&&p[pos]==p[pos+1])--pos;
		//cout<<pos<<"Pos\n";
		int ans[3]={0,0,0},pp=1;
		rep(i,1,pos+1){
			if(p[i]!=p[i-1]&&ans[0]){
				pp=i;
				//cout<<pp<<"PP\n";
				break;
			}
			++ans[0];
		}
		//cout<<ans[0]<<"ans0\n";
		rep(i,pp,pos+1){
			if(p[i]!=p[i-1]&&ans[1]>ans[0]){
				pp=i;
				break;
			}
			++ans[1];
		}
		//cout<<ans[1]<<"ans1\n";
		ans[2]=pos-ans[0]-ans[1];
		if(!ans[2]||ans[0]>=ans[1]||ans[0]>=ans[2]){
			printf("0 0 0\n");
		}
		else printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	}
}