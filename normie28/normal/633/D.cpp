#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
map<int,int> cnt,tmp;
vector<int> used;
int a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		tmp[a[i]]++;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=0;k<(int)used.size();k++)
				tmp[used[k]]=cnt[used[k]];
			used.clear();
			int last=a[i],last_sec=a[j];
			tmp[last]--;
			tmp[last_sec]--;
			used.push_back(last);
			used.push_back(last_sec);
			int len=2;
			while(tmp[last+last_sec]){
				if(last==0 && last_sec==0){
					len+=tmp[0];
					break;
				}
				int next_last=last+last_sec;
				tmp[next_last]--;
				last_sec=last;
				last=next_last;
				len++;
				used.push_back(last);
			}
			res=max(res,len);
		}
	}
	cout<<res;
}