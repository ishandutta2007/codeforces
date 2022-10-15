#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define N 100010
int occ1[2*N], occ2[2*N];
int bef1[N], bef2[N], A[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int rt = 10000000;
	for(int i=1;i<=2*n;i++){
		occ1[i] = rt;
		occ2[i] = rt;
	}
	int p1 = 1, p2 = 1;
	for(int i=0;i<n;i++){
		cin>>A[i];
		A[i]--;
		if(!A[i])
			occ1[p1++] = i;
		else occ2[p2++] = i;
		bef1[i+1] = p1 - 1;
		bef2[i+1] = p2 - 1;
	}
	int mk = A[n-1] + 1;
	vector<pair<int,int> > ans;
	for(int i = 1;i<=n;i++){
		int curpos = 0, w1 = 0, w2 = 0, nop = 0;
		while(1){
			int nex1 = occ1[bef1[curpos] + i], nex2 = occ2[bef2[curpos] + i];
			if(curpos == n)
				break;
			if(nex1 == nex2){
				nop = 1;
				break;
			}
			else if(nex1 < nex2){
				w1++;
				curpos = nex1 + 1;
			}
			else{
				w2++;
				curpos = nex2 + 1;
			}
		}
		if(!nop && w1 != w2){
			if(mk == 1 && w1 > w2)
				ans.pb(mp(w1, i));
			else if(mk == 2 && w2 > w1)
				ans.pb(mp(w2,i));
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}