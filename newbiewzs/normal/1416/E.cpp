#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
const int N=5e5+55;
int T,n;
int a[N];
set<pii>yi;
set<pii>::iterator it,iv;
int ling,er;
signed main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		//cout<<T<<endl;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		yi.clear();
		ling=0;er=-1;
		int x=1,y=0;
		for(int i=1;i<=n;i++){
			if(i==5){
				new char;
			}
			if(er!=-1){
				ling+=2;
				yi.clear();
				x=1;y=0;
				if(a[i]-er>0){
					yi.insert(mp(a[i]-er,a[i]-er));
				}
			}
			else if(yi.size()){
				ling++;
				if(x==1){
					it=yi.end();
					it--;
					while(yi.size() && it->fi + y >= a[i]){
						iv=it;
						if(yi.size()>1)iv--;
						yi.erase(it);
						if(yi.size())it=iv;
					}
					//while(yi.size() && it)
					if(yi.size() and it->se + y >=a[i]){
						int L=it->first;
						yi.erase(it);
						if(a[i]-y-1>=L){
							yi.insert(mp(L,a[i]-y-1));
						}
					}
				}
				else{
					it=yi.begin();
					while(yi.size() && -(it->se) + y >= a[i]){
						iv=it;
						if(it!=yi.end())iv++;
						yi.erase(it);
						if(yi.size())it=iv;
					}
					if(yi.size() and -(it->fi) + y >=a[i]){
						int R=it->se;
						yi.erase(it);
						if(y+1-a[i]<=R){
							yi.insert(mp(y+1-a[i],R));
						}
					}
				}
				x*=-1;
				y=a[i]-y;
			}
			else{
				//yi.clear();
				x=1;y=0;
				er=-1;
				if(max(a[i]-a[i-1]+1,1ll)<=a[i]-1)yi.insert(mp(max(a[i]-a[i-1]+1,1ll),a[i]-1));
			}
			er=-1;
			if(a[i]&1)continue;
			int z=a[i]/2;
			int pos=x*(z-y);
			it=yi.lower_bound(mp(pos+1,pos+1));
			if(it!=yi.begin())it--;
			if(it->fi<=pos and it->se>=pos and yi.size())
			{
				int L=it->fi;
				int R=it->se;
				yi.erase(it);
				er=z;
				yi.insert(mp(L,pos-1));
				yi.insert(mp(pos+1,R));
			}
			else yi.insert(mp(pos,pos));
		}
		if(er!=-1){
			printf("%lld\n",n*2-(ling+2));
		}
		else if(yi.size()){
			printf("%lld\n",n*2-(ling+1));
		}
		else{
			printf("%lld\n",n*2-ling);
		}
	}
	return 0;
}